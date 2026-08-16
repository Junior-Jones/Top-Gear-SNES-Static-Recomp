#include "../sc_static_apu.h"
void SMP::tick() {
  timer0.tick();
  timer1.tick();
  timer2.tick();

  clock++;
  dsp.clock++;
}

void SMP::tick(unsigned clocks) {
  timer0.tick(clocks);
  timer1.tick(clocks);
  timer2.tick(clocks);

  clock += clocks;
  dsp.clock += clocks;
}

void SMP::op_io() {
  tick();
}

void SMP::op_io(unsigned clocks) {
  tick(clocks);
}

uint8 SMP::op_read(uint16 addr) {
  tick();
  if((addr & 0xfff0) == 0x00f0) return mmio_read(addr);
  if(addr >= 0xffc0 && status.iplrom_enable) return iplrom[addr & 0x3f];
  return apuram[addr];
}

void SMP::op_write(uint16 addr, uint8 data) {
  tick();
  if(!sc_static_apu_trace_aram_write_event(addr,data)) {
    sc_aot_fail(4u,regs.pc,0xffu,data);
    return;
  }
  if((addr & 0xfff0) == 0x00f0) mmio_write(addr, data);
  apuram[addr] = data;
}

uint8 SMP::op_readstack()
{
  tick();
  return apuram[0x0100 | ++regs.sp];
}

void SMP::op_writestack(uint8 data)
{
  tick();
  const uint16 addr=(uint16)(0x0100 | regs.sp);
  if(sc_static_apu_trace_aram_write_event(addr,data)) apuram[addr]=data;
  else {
    sc_aot_fail(4u,regs.pc,0xffu,data);
  }
  regs.sp--;
}

void SMP::op_step() {
  #define op_readpc() op_read(regs.pc++)
  #define op_readdp(addr) op_read((regs.p.p << 8) + ((addr) & 0xff))
  #define op_writedp(addr, data) op_write((regs.p.p << 8) + ((addr) & 0xff), data)
  #define op_readaddr(addr) op_read(addr)
  #define op_writeaddr(addr, data) op_write(addr, data)

  if(opcode_cycle == 0)
  {
    const uint16 opcode_pc = regs.pc;
    ++instruction_count;
    opcode_number = op_readpc();
    sc_static_apu_trace_instruction_event(opcode_pc, static_cast<uint8>(opcode_number));
    if(!sc_aot_prepare(opcode_pc, static_cast<uint8>(opcode_number))) return;
  }

  #include "sc_smp_aot_dispatch.inc"
}
