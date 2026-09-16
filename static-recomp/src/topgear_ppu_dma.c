#include "topgear_internal.h"

#include <string.h>

/* TOP GEAR PPU/DMA MAP (Version 26): BGMODE $2105 selects Mode 1 menu/HUD or
   Mode 7 race-road rendering.  $2107-$2114 own BG map/character/scroll state;
   $211A-$2120 own Mode 7 matrix/centre state.  OAM/VRAM/CGRAM storage ports are
   fed by Top Gear's DMA-heavy graphics setup regions. */

static uint8_t vram_increment(uint8_t vmain) {
    static const uint8_t increments[4] = {1u, 32u, 128u, 128u};
    return increments[vmain & 3u];
}

static uint16_t mapped_vram_word_address(const TopGearRecomp *i) {
    const uint16_t a = i->vram_word_address;
    switch (i->vram_mapping & 3u) {
    case 0u:
        return a;
    case 1u:
        return (uint16_t)((a & 0xFF00u) | ((a & 0x001Fu) << 3) | ((a >> 5) & 7u));
    case 2u:
        return (uint16_t)((a & 0xFE00u) | ((a & 0x003Fu) << 3) | ((a >> 6) & 7u));
    case 3u:
        return (uint16_t)((a & 0xFC00u) | ((a & 0x007Fu) << 3) | ((a >> 7) & 7u));
    default:
        return a;
    }
}

static uint16_t vram_word(const TopGearRecomp *i) {
    const uint32_t address = ((uint32_t)mapped_vram_word_address(i) << 1) & 0xFFFFu;
    return (uint16_t)(i->vram[address] | ((uint16_t)i->vram[(address + 1u) & 0xFFFFu] << 8));
}

static void reload_vram_latch(TopGearRecomp *i) {
    i->vram_read_latch = vram_word(i);
}

static void advance_vram(TopGearRecomp *i) {
    i->vram_word_address = (uint16_t)(i->vram_word_address + i->vram_increment_words);
}

static void write_oam(TopGearRecomp *i, uint8_t value) {
    const uint16_t address = (uint16_t)(i->oam_byte_address % 544u);
    if (address < 512u) {
        if ((address & 1u) == 0u) {
            i->oam_latch_low = value;
            i->oam_latch_pending = 1u;
        } else {
            i->oam[(uint16_t)(address - 1u)] = i->oam_latch_pending ? i->oam_latch_low : i->oam[(uint16_t)(address - 1u)];
            i->oam[address] = value;
            i->oam_write_count += 2u;
            i->oam_latch_pending = 0u;
        }
    } else {
        i->oam[address] = value;
        i->oam_write_count++;
    }
    i->oam_byte_address = (uint16_t)((i->oam_byte_address + 1u) % 544u);
}

int tg_ppu_write(TopGearRecomp *i, uint16_t a, uint8_t v) {
    tg_v25_note_mmio_write(i,a);
    uint32_t byte_address;
    if (!i || a < 0x2100u || a > 0x21FFu) return 0;
    i->ppu_registers[a - 0x2100u] = v;
    switch (a) {
    case 0x2100u:
        i->forced_blank = (uint8_t)((v >> 7) & 1u);
        i->brightness = (uint8_t)(v & 15u);
        break;
    case 0x2102u:
        i->oam_byte_address = (uint16_t)((i->oam_byte_address & 0x200u) | ((uint16_t)v << 1));
        i->oam_latch_pending = 0u;
        break;
    case 0x2103u:
        i->oam_byte_address = (uint16_t)(((uint16_t)(v & 1u) << 9) | (i->oam_byte_address & 0x1FEu));
        i->oam_priority_rotation = (uint8_t)((v >> 7) & 1u);
        i->oam_latch_pending = 0u;
        break;
    case 0x2104u:
        write_oam(i, v);
        break;
    case 0x2105u:
        i->v24_observed_bgmode_mask |= (uint8_t)(1u << (v & 7u));
        break;
    case 0x2107u:
    case 0x210Bu:
    case 0x212Cu:
        break;
    case 0x210Du:
        i->mode7_hofs = (uint16_t)(((uint16_t)v << 8) | i->mode7_latch);
        i->mode7_latch = v;
        i->bg_scroll[0] = (uint16_t)(((uint16_t)v << 8) | (i->bgofs_ppu1_latch & 0xF8u) | (i->bgofs_ppu2_latch & 7u));
        i->bgofs_ppu1_latch = v; i->bgofs_ppu2_latch = v; i->bg1_hofs=i->bg_scroll[0];
        break;
    case 0x210Eu:
        i->mode7_vofs = (uint16_t)(((uint16_t)v << 8) | i->mode7_latch);
        i->mode7_latch = v;
        i->bg_scroll[1] = (uint16_t)(((uint16_t)v << 8) | i->bgofs_ppu1_latch);
        i->bgofs_ppu1_latch = v; i->bg1_vofs=i->bg_scroll[1];
        break;
    case 0x210Fu: case 0x2111u: case 0x2113u: {
        unsigned layer=(unsigned)((a-0x210Fu)/2u)+1u;
        i->bg_scroll[layer*2u]=(uint16_t)(((uint16_t)v<<8)|(i->bgofs_ppu1_latch&0xF8u)|(i->bgofs_ppu2_latch&7u));
        i->bgofs_ppu1_latch=v;i->bgofs_ppu2_latch=v;break;
    }
    case 0x2110u: case 0x2112u: case 0x2114u: {
        unsigned layer=(unsigned)((a-0x2110u)/2u)+1u;
        i->bg_scroll[layer*2u+1u]=(uint16_t)(((uint16_t)v<<8)|i->bgofs_ppu1_latch);
        i->bgofs_ppu1_latch=v;break;
    }
    case 0x211Bu:
        i->v14_m7a=(uint16_t)(((uint16_t)v<<8)|i->mode7_latch);i->mode7_latch=v;
        i->v14_m7a_latch=v;i->v14_m7a_pending=0u;break;
    case 0x211Cu:
        i->v14_m7b=(uint16_t)(((uint16_t)v<<8)|i->mode7_latch);i->mode7_latch=v;
        i->v14_m7b_latch=v;i->v14_m7b_pending=0u;break;
    case 0x211Du:
        i->mode7_c=(uint16_t)(((uint16_t)v<<8)|i->mode7_latch);i->mode7_latch=v;break;
    case 0x211Eu:
        i->mode7_d=(uint16_t)(((uint16_t)v<<8)|i->mode7_latch);i->mode7_latch=v;break;
    case 0x211Fu:
        i->mode7_x=(uint16_t)(((uint16_t)v<<8)|i->mode7_latch);i->mode7_latch=v;break;
    case 0x2120u:
        i->mode7_y=(uint16_t)(((uint16_t)v<<8)|i->mode7_latch);i->mode7_latch=v;break;
    case 0x2115u:
        i->vram_increment_words = vram_increment(v);
        i->vram_mapping = (uint8_t)((v >> 2) & 3u);
        i->vram_increment_after_high = (uint8_t)((v >> 7) & 1u);
        break;
    case 0x2116u:
        i->vram_word_address = (uint16_t)((i->vram_word_address & 0xFF00u) | v);
        reload_vram_latch(i);
        break;
    case 0x2117u:
        i->vram_word_address = (uint16_t)((i->vram_word_address & 0x00FFu) | ((uint16_t)v << 8));
        reload_vram_latch(i);
        break;
    case 0x2118u:
        byte_address = ((uint32_t)mapped_vram_word_address(i) << 1) & 0xFFFFu;
        i->vram[byte_address] = v;
        i->vram_write_count++;
        if (!i->vram_increment_after_high) advance_vram(i);
        break;
    case 0x2119u:
        byte_address = (((uint32_t)mapped_vram_word_address(i) << 1) + 1u) & 0xFFFFu;
        i->vram[byte_address] = v;
        i->vram_write_count++;
        if (i->vram_increment_after_high) advance_vram(i);
        break;
    case 0x2121u:
        i->cgram_byte_address = (uint16_t)((uint16_t)v << 1);
        i->cgram_latch_pending = 0u;
        break;
    case 0x2122u:
        if (!i->cgram_latch_pending) {
            i->cgram_latch_low = v;
            i->cgram_latch_pending = 1u;
        } else {
            i->cgram[i->cgram_byte_address & 0x1FFu] = i->cgram_latch_low;
            i->cgram[(i->cgram_byte_address + 1u) & 0x1FFu] = (uint8_t)(v & 0x7Fu);
            i->cgram_byte_address = (uint16_t)((i->cgram_byte_address + 2u) & 0x1FFu);
            i->cgram_latch_pending = 0u;
            i->cgram_write_count += 2u;
        }
        break;
    case 0x2132u: {
        uint16_t component=(uint16_t)(v&31u);
        if(v&0x20u)i->ppu_fixed_color=(uint16_t)((i->ppu_fixed_color&~31u)|component);
        if(v&0x40u)i->ppu_fixed_color=(uint16_t)((i->ppu_fixed_color&~(31u<<5))|(component<<5));
        if(v&0x80u)i->ppu_fixed_color=(uint16_t)((i->ppu_fixed_color&~(31u<<10))|(component<<10));
        break;
    }
    case 0x2180u:
        i->wram[i->wram_port_address & 0x1FFFFu] = v;
        i->wram_port_address = (i->wram_port_address + 1u) & 0x1FFFFu;
        break;
    case 0x2181u:
        i->wram_port_address = (i->wram_port_address & 0x1FF00u) | v;
        break;
    case 0x2182u:
        i->wram_port_address = (i->wram_port_address & 0x100FFu) | ((uint32_t)v << 8);
        break;
    case 0x2183u:
        i->wram_port_address = (i->wram_port_address & 0x0FFFFu) | ((uint32_t)(v & 1u) << 16);
        break;
    default:
        break;
    }
    return 1;
}

int tg_ppu_read(TopGearRecomp *i, uint16_t a, uint8_t *v) {
    tg_v25_note_mmio_read(i,a);
    if (!i || !v || a < 0x2100u || a > 0x21FFu) return 0;
    switch (a) {
    case 0x2134u:
    case 0x2135u:
    case 0x2136u: {
        int32_t product = (int32_t)(int16_t)i->v14_m7a * (int32_t)(int8_t)(i->v14_m7b >> 8);
        uint32_t bits = (uint32_t)product & 0x00FFFFFFu;
        *v = (uint8_t)(bits >> (8u * (uint32_t)(a - 0x2134u)));
        return 1;
    }
    case 0x2138u:
        *v = i->oam[i->oam_byte_address % 544u];
        i->oam_byte_address = (uint16_t)((i->oam_byte_address + 1u) % 544u);
        return 1;
    case 0x2139u:
        *v = (uint8_t)i->vram_read_latch;
        if (!i->vram_increment_after_high) {
            reload_vram_latch(i);
            advance_vram(i);
        }
        return 1;
    case 0x213Au:
        *v = (uint8_t)(i->vram_read_latch >> 8);
        if (i->vram_increment_after_high) {
            reload_vram_latch(i);
            advance_vram(i);
        }
        return 1;
    case 0x213Bu:
        *v = i->cgram[i->cgram_byte_address & 0x1FFu];
        if ((i->cgram_byte_address & 1u) != 0u) *v &= 0x7Fu;
        i->cgram_byte_address = (uint16_t)((i->cgram_byte_address + 1u) & 0x1FFu);
        return 1;
    case 0x2180u:
        *v = i->wram[i->wram_port_address & 0x1FFFFu];
        i->wram_port_address = (i->wram_port_address + 1u) & 0x1FFFFu;
        return 1;
    default:
        *v = i->ppu_registers[a - 0x2100u];
        return 1;
    }
}

static int dma_valid_a(uint32_t address) {
    if ((address & 0x40FF00u) == 0x002100u) return 0;
    if ((address & 0x40FE00u) == 0x004000u) return 0;
    if ((address & 0x40FFE0u) == 0x004200u) return 0;
    if ((address & 0x40FF80u) == 0x004300u) return 0;
    return 1;
}

static int dma_wram_offset(uint32_t address, uint32_t *offset) {
    const uint8_t bank = (uint8_t)(address >> 16);
    const uint16_t local = (uint16_t)address;
    if (bank == 0x7Eu || bank == 0x7Fu) {
        *offset = ((uint32_t)(bank - 0x7Eu) << 16) | local;
        return 1;
    }
    if ((bank <= 0x3Fu || (bank >= 0x80u && bank <= 0xBFu)) && local < 0x2000u) {
        *offset = local;
        return 1;
    }
    return 0;
}

static int dma_read_a(TopGearRecomp *i, uint32_t address, uint8_t *value) {
    if (!dma_valid_a(address)) {
        *value = 0u;
        return 1;
    }
    return tg_bus_read8(i, address, value);
}

static int dma_write_a(TopGearRecomp *i, uint32_t address, uint8_t value) {
    uint32_t offset;
    if (!dma_valid_a(address)) return 1;
    if (dma_wram_offset(address, &offset)) {
        i->wram[offset] = value;
        i->scpu_bus_writes++;
        return 1;
    }
    /* Cartridge ROM writes and other unimplemented A-bus destinations are
       ignored by this Version 08 DMA slice rather than promoted as storage. */
    return 1;
}

static uint8_t dma_bbus_offset(uint8_t mode, uint32_t index) {
    static const uint8_t pattern[8][4] = {
        {0u, 0u, 0u, 0u},
        {0u, 1u, 0u, 1u},
        {0u, 0u, 0u, 0u},
        {0u, 0u, 1u, 1u},
        {0u, 1u, 2u, 3u},
        {0u, 1u, 0u, 1u},
        {0u, 0u, 0u, 0u},
        {0u, 0u, 1u, 1u}
    };
    static const uint8_t length[8] = {1u, 2u, 2u, 4u, 4u, 4u, 2u, 4u};
    return pattern[mode & 7u][index % length[mode & 7u]];
}

static int dma_transfer_channel(TopGearRecomp *i, unsigned channel) {
    const uint16_t base = (uint16_t)(0x4300u + channel * 0x10u);
    const uint32_t reg = (uint32_t)(base - 0x4200u);
    const uint8_t dmap = i->cpu_io_registers[reg + 0u];
    const uint8_t target = i->cpu_io_registers[reg + 1u];
    uint16_t source16 = (uint16_t)(i->cpu_io_registers[reg + 2u] | ((uint16_t)i->cpu_io_registers[reg + 3u] << 8));
    const uint8_t source_bank = i->cpu_io_registers[reg + 4u];
    const uint16_t size16 = (uint16_t)(i->cpu_io_registers[reg + 5u] | ((uint16_t)i->cpu_io_registers[reg + 6u] << 8));
    const uint32_t transfer_bytes = size16 ? size16 : 65536u;
    const uint8_t mode = (uint8_t)(dmap & 7u);
    const uint8_t fixed = (uint8_t)((dmap >> 3) & 1u);
    const uint8_t decrement = (uint8_t)((dmap >> 4) & 1u);
    const uint8_t direction = (uint8_t)((dmap >> 7) & 1u);
    uint32_t index;

    if (!tg_v16_capture_dma_channel(i,channel,dmap,target,source16,source_bank,transfer_bytes)) return 0;
    i->dma_last_channel = (uint8_t)channel;
    i->dma_last_mode = mode;
    i->dma_last_direction = direction;
    i->dma_last_source_address = ((uint32_t)source_bank << 16) | source16;
    i->dma_last_transfer_bytes = transfer_bytes;
    i->dma_last_bbus_sequence_count = 0u;
    i->dma_transfer_modes_seen_mask |= (uint8_t)(1u << mode);
    i->dma_directions_seen_mask |= (uint8_t)(1u << direction);
    if (!size16) i->dma_zero_size_transfers++;

    /* Global + per-channel setup. Transfer byte timing is accounted at eight
       master clocks per byte. Alignment and edge timing remain unclaimed. */
    i->dma_master_clocks_accounted += 16u;
    for (index = 0u; index < transfer_bytes; ++index) {
        const uint32_t address_a = ((uint32_t)source_bank << 16) | source16;
        const uint8_t address_b = (uint8_t)(target + dma_bbus_offset(mode, index));
        uint8_t data = 0u;
        int ok;
        if (!direction) {
            ok = dma_read_a(i, address_a, &data) && tg_ppu_write(i, (uint16_t)(0x2100u | address_b), data);
        } else {
            ok = tg_ppu_read(i, (uint16_t)(0x2100u | address_b), &data) && dma_write_a(i, address_a, data);
        }
        if (!ok) return 0;
        if (!tg_v16_capture_dma_byte(i,channel,index,address_a,address_b,data)) return 0;
        if (i->dma_last_bbus_sequence_count < 16u) {
            const uint8_t n = i->dma_last_bbus_sequence_count++;
            i->dma_last_bbus_sequence[n] = address_b;
            i->dma_last_data[n] = data;
        }
        if (!fixed) source16 = decrement ? (uint16_t)(source16 - 1u) : (uint16_t)(source16 + 1u);
        i->dma_bytes_transferred++;
        i->dma_master_clocks_accounted += 8u;
    }
    i->cpu_io_registers[reg + 2u] = (uint8_t)source16;
    i->cpu_io_registers[reg + 3u] = (uint8_t)(source16 >> 8);
    i->cpu_io_registers[reg + 5u] = 0u;
    i->cpu_io_registers[reg + 6u] = 0u;
    i->dma_channels_completed++;
    i->dma_completed_mask |= (uint8_t)(1u << channel);
    return 1;
}

int tg_dma_latch_write(TopGearRecomp *i, uint16_t a, uint8_t v) {
    if (!i || a < 0x4200u || a > 0x43FFu) return 0;
    i->cpu_io_registers[a - 0x4200u] = v;
    if (a == 0x420Bu) {
        i->dma_enable_mask = v;
        i->dma_launch_count++;
    }
    return 1;
}

int tg_dma_io_write(TopGearRecomp *i, uint16_t a, uint8_t v) {
    unsigned channel;
    if (!tg_dma_latch_write(i, a, v)) return 0;
    switch (a) {
    case 0x4200u:
        i->nmitimen = v;
        break;
    case 0x4202u:
        i->v14_wrmpya = v;
        break;
    case 0x4203u:
        i->v14_wrmpyb = v;
        i->v14_rdmpy = (uint16_t)((uint16_t)i->v14_wrmpya * (uint16_t)v);
        i->v14_rddiv = (uint16_t)(((uint16_t)v << 8) | i->v14_wrmpya);
        break;
    case 0x4204u:
        i->v14_wrdiva = (uint16_t)((i->v14_wrdiva & 0xFF00u) | v);
        break;
    case 0x4205u:
        i->v14_wrdiva = (uint16_t)((i->v14_wrdiva & 0x00FFu) | ((uint16_t)v << 8));
        break;
    case 0x4206u:
        i->v14_wrdivb = v;
        if (v) { i->v14_rddiv = (uint16_t)(i->v14_wrdiva / v); i->v14_rdmpy = (uint16_t)(i->v14_wrdiva % v); }
        else { i->v14_rddiv = 0xFFFFu; i->v14_rdmpy = i->v14_wrdiva; }
        break;
    case 0x4207u:
        i->htime_target = (uint16_t)((i->htime_target & 0x100u) | v);
        break;
    case 0x4208u:
        i->htime_target = (uint16_t)((i->htime_target & 0x0FFu) | ((uint16_t)(v & 1u) << 8));
        break;
    case 0x4209u:
        i->vtime_target = (uint16_t)((i->vtime_target & 0x100u) | v);
        break;
    case 0x420Au:
        i->vtime_target = (uint16_t)((i->vtime_target & 0x0FFu) | ((uint16_t)(v & 1u) << 8));
        break;
    case 0x420Cu:
        /* Native live-race raster setup enables channels 0-6 together.
           Observe the shared bus so ROM and copied-WRAM execution agree. */
        if(v==0x7Fu&&i->mod_audio_menu_context&&!i->mod_menu_remodel_active)
            tg_mod_audio_gameplay_start(i);
        i->hdma_enable_mask = v;
        tg_v16_note_hdma_enable(i,v);
        break;
    case 0x420Bu:
        i->dma_completed_mask = 0u;
        i->dma_master_clocks_accounted += v ? 8u : 0u;
        for (channel = 0u; channel < 8u; ++channel) {
            if ((v & (uint8_t)(1u << channel)) != 0u && !dma_transfer_channel(i, channel)) return 0;
        }
        break;
    default:
        break;
    }
    return 1;
}

static void complete_autojoy(TopGearRecomp *i) {
    unsigned n;
    i->autojoy_result[0] = i->controller_state[0];
    i->autojoy_result[1] = i->controller_state[1];
    i->autojoy_result[2] = 0u;
    i->autojoy_result[3] = 0u;
    for (n = 0u; n < 4u; ++n) {
        i->cpu_io_registers[0x18u + n * 2u] = (uint8_t)i->autojoy_result[n];
        i->cpu_io_registers[0x19u + n * 2u] = (uint8_t)(i->autojoy_result[n] >> 8);
    }
    i->autojoy_busy = 0u;
    i->autojoy_master_clocks_remaining = 0u;
}

int tg_cpu_io_read(TopGearRecomp *i, uint16_t a, uint8_t *v) {
    if (!i || !v || a < 0x4200u || a > 0x43FFu) return 0;
    if(i->v16_handler_timing_mode&&i->v16_timed_read_count){
        uint8_t pos=i->v16_timed_read_head;
        if(i->v16_timed_read_address[pos]!=a)return tg_fail_frontier(i,"Version 16 timed CPU-I/O read order diverged from generated semantics.",NULL);
        *v=i->v16_timed_read_value[pos];
        i->v16_timed_read_head=(uint8_t)((pos+1u)&7u);i->v16_timed_read_count--;
        return 1;
    }
    switch (a) {
    case 0x4214u: *v = (uint8_t)i->v14_rddiv; return 1;
    case 0x4215u: *v = (uint8_t)(i->v14_rddiv >> 8); return 1;
    case 0x4216u: *v = (uint8_t)i->v14_rdmpy; return 1;
    case 0x4217u: *v = (uint8_t)(i->v14_rdmpy >> 8); return 1;
    case 0x4210u:
        *v = (uint8_t)((i->nmi_flag ? 0x80u : 0u) | 2u);
        i->nmi_flag = 0u;
        return 1;
    case 0x4211u:
        *v = i->irq_flag ? 0x80u : 0u;
        i->irq_flag = 0u;
        return 1;
    case 0x4212u:
        if(i->v22_semantic_main_mode&&!i->v23_event_mode){
            i->v22_semantic_hblank_read_count++;
            i->v22_semantic_hblank_toggle ^= 1u;
            *v=(uint8_t)((i->vcounter_line >= 225u ? 0x80u : 0u) |
                         (i->v22_semantic_hblank_toggle ? 0x40u : 0u) |
                         (i->autojoy_busy ? 1u : 0u));
        }else{
            *v = (uint8_t)((i->vcounter_line >= 225u ? 0x80u : 0u) |
                           ((i->hcounter_master < 4u || i->hcounter_master >= 1096u) ? 0x40u : 0u) |
                           (i->autojoy_busy ? 1u : 0u));
        }
        return 1;
    default:
        *v = i->cpu_io_registers[a - 0x4200u];
        return 1;
    }
}

int topgear_recomp_v07_ppu_port_write(TopGearRecomp *i, uint16_t a, uint8_t v) { return tg_ppu_write(i, a, v); }
int topgear_recomp_v07_ppu_port_read(TopGearRecomp *i, uint16_t a, uint8_t *v) { return tg_ppu_read(i, a, v); }
int topgear_recomp_v07_dma_register_write(TopGearRecomp *i, uint16_t a, uint8_t v) { return tg_dma_latch_write(i, a, v); }
int topgear_recomp_v07_dma_register_read(const TopGearRecomp *i, uint16_t a, uint8_t *v) {
    if (!i || !v || a < 0x4200u || a > 0x43FFu) return 0;
    *v = i->cpu_io_registers[a - 0x4200u];
    return 1;
}
int topgear_recomp_v08_dma_register_write(TopGearRecomp *i, uint16_t a, uint8_t v) { return tg_dma_io_write(i, a, v); }
int topgear_recomp_v08_cpu_io_write(TopGearRecomp *i, uint16_t a, uint8_t v) { return tg_dma_io_write(i, a, v); }
int topgear_recomp_v08_cpu_io_read(TopGearRecomp *i, uint16_t a, uint8_t *v) { return tg_cpu_io_read(i, a, v); }

static int copy_range(const uint8_t *src, size_t total, uint32_t off, void *out, size_t n) {
    if (!src || !out || off > total || n > total - off) return 0;
    memcpy(out, src + off, n);
    return 1;
}
int topgear_recomp_v07_read_vram(const TopGearRecomp *i, uint32_t o, void *v, size_t n) { return i && copy_range(i->vram, sizeof(i->vram), o, v, n); }
int topgear_recomp_v07_read_oam(const TopGearRecomp *i, uint32_t o, void *v, size_t n) { return i && copy_range(i->oam, sizeof(i->oam), o, v, n); }
int topgear_recomp_v07_read_cgram(const TopGearRecomp *i, uint32_t o, void *v, size_t n) { return i && copy_range(i->cgram, sizeof(i->cgram), o, v, n); }

int topgear_recomp_v07_ppu_storage_info(const TopGearRecomp *i, TopGearV07PpuStorageInfo *x) {
    if (!i || !x) return 0;
    memset(x, 0, sizeof(*x));
    x->vram_word_address = i->vram_word_address;
    x->oam_byte_address = i->oam_byte_address;
    x->cgram_byte_address = (uint8_t)(i->cgram_byte_address & 0xFFu);
    x->vram_increment_words = i->vram_increment_words;
    x->vram_increment_after_high = i->vram_increment_after_high;
    x->forced_blank = i->forced_blank;
    x->brightness = i->brightness;
    x->vram_write_count = i->vram_write_count;
    x->oam_write_count = i->oam_write_count;
    x->cgram_write_count = i->cgram_write_count;
    x->dma_launch_count = i->dma_launch_count;
    x->dma_enable_mask = i->dma_enable_mask;
    return 1;
}

int topgear_recomp_v07_bus_event_info(const TopGearRecomp *i, TopGearV07BusEventInfo *x) {
    if (!i || !x) return 0;
    memset(x, 0, sizeof(*x));
    x->total_bus_reads = i->scpu_bus_reads;
    x->total_bus_writes = i->scpu_bus_writes;
    x->apu_port_reads = i->scpu_apu_reads;
    x->apu_port_writes = i->scpu_apu_writes;
    x->ppu_port_reads = i->scpu_ppu_reads;
    x->ppu_port_writes = i->scpu_ppu_writes;
    x->cpu_io_reads = i->scpu_cpuio_reads;
    x->cpu_io_writes = i->scpu_cpuio_writes;
    x->dma_launch_events = i->dma_launch_count;
    x->last_dma_enable_mask = i->dma_enable_mask;
    x->exact_scpu_master_clock_timing = 0u;
    x->ppu_storage_ports_implemented = 1u;
    x->dma_register_latches_implemented = 1u;
    return 1;
}

int topgear_recomp_v08_dma_info(const TopGearRecomp *i, TopGearV08DmaInfo *x) {
    if (!i || !x) return 0;
    memset(x, 0, sizeof(*x));
    x->bytes_transferred = i->dma_bytes_transferred;
    x->master_clocks_accounted = i->dma_master_clocks_accounted;
    x->channels_completed = i->dma_channels_completed;
    x->launch_count = i->dma_launch_count;
    x->zero_size_transfers = i->dma_zero_size_transfers;
    x->last_source_address = i->dma_last_source_address;
    x->last_transfer_bytes = i->dma_last_transfer_bytes;
    x->requested_mask = i->dma_enable_mask;
    x->completed_mask = i->dma_completed_mask;
    x->transfer_modes_seen_mask = i->dma_transfer_modes_seen_mask;
    x->directions_seen_mask = i->dma_directions_seen_mask;
    x->last_channel = i->dma_last_channel;
    x->last_mode = i->dma_last_mode;
    x->last_direction = i->dma_last_direction;
    x->exact_master_clock_timing = 0u;
    x->last_bbus_sequence_count = i->dma_last_bbus_sequence_count;
    memcpy(x->last_bbus_sequence, i->dma_last_bbus_sequence, sizeof(x->last_bbus_sequence));
    memcpy(x->last_data, i->dma_last_data, sizeof(x->last_data));
    tg_sha256_hex(i->vram, sizeof(i->vram), x->vram_sha256);
    tg_sha256_hex(i->oam, sizeof(i->oam), x->oam_sha256);
    tg_sha256_hex(i->cgram, sizeof(i->cgram), x->cgram_sha256);
    return 1;
}

int topgear_recomp_v08_set_controller_state(TopGearRecomp *i, unsigned port, uint16_t state) {
    if (!i || port >= 2u) return 0;
    i->controller_state[port] = (uint16_t)(state & 0xFFF0u);
    return 1;
}

int topgear_recomp_v08_begin_vblank(TopGearRecomp *i) {
    if (!i) return 0;
    i->nmi_flag = 1u;
    if ((i->nmitimen & 1u) != 0u) {
        i->autojoy_busy = 1u;
        i->autojoy_master_clocks_remaining = 4224u;
    }
    return 1;
}

int topgear_recomp_v08_advance_master_clocks(TopGearRecomp *i, uint32_t clocks) {
    uint32_t remaining = clocks;
    if (!i) return 0;
    i->scpu_master_clock += clocks;
    while (remaining != 0u) {
        const uint32_t to_line = 1364u - i->hcounter_master;
        const uint32_t step = remaining < to_line ? remaining : to_line;
        i->hcounter_master = (uint16_t)(i->hcounter_master + step);
        remaining -= step;
        if (i->hcounter_master == 1364u) {
            i->hcounter_master = 0u;
            i->vcounter_line = (uint16_t)((i->vcounter_line + 1u) % 262u);
            if (i->vcounter_line == 225u) (void)topgear_recomp_v08_begin_vblank(i);
            if (i->vcounter_line == 0u) i->nmi_flag = 0u;
        }
    }
    if (i->autojoy_busy) {
        if (clocks >= i->autojoy_master_clocks_remaining) complete_autojoy(i);
        else i->autojoy_master_clocks_remaining -= clocks;
    }
    return 1;
}

int topgear_recomp_v08_interrupt_input_info(const TopGearRecomp *i, TopGearV08InterruptInputInfo *x) {
    if (!i || !x) return 0;
    memset(x, 0, sizeof(*x));
    x->nmitimen = i->nmitimen;
    x->nmi_flag = i->nmi_flag;
    x->irq_flag = i->irq_flag;
    x->autojoy_enabled = (uint8_t)(i->nmitimen & 1u);
    x->autojoy_busy = i->autojoy_busy;
    x->exact_autojoy_start_timing = 0u;
    x->htime_target = i->htime_target;
    x->vtime_target = i->vtime_target;
    memcpy(x->controller_state, i->controller_state, sizeof(x->controller_state));
    memcpy(x->autojoy_result, i->autojoy_result, sizeof(x->autojoy_result));
    x->autojoy_master_clocks_remaining = i->autojoy_master_clocks_remaining;
    x->scpu_master_clock = i->scpu_master_clock;
    x->hcounter_master = i->hcounter_master;
    x->vcounter_line = i->vcounter_line;
    return 1;
}
