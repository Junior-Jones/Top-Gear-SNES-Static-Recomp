"""Natural controller route: compare visible tilemap with captured live RAM.
Usage: python test_menu_summary_headless.py RUNNER ROM OUTPUT_DIRECTORY
No game-state writes, save imports, or timing shortcuts.
"""
import pathlib
import subprocess
import sys

runner, rom, output = map(pathlib.Path, sys.argv[1:])
output.mkdir(parents=True, exist_ok=True)
events = [(0, 'NONE', 'boot'), (26000, 'START', 'title'), (28000, 'NONE', 'release')]
checks = {}
clock = 32000

def capture(label, page=None, players=None):
    global clock
    index = len(events)
    events.append((clock, 'NONE', 'capture-' + label))
    if page:
        checks[index] = (label, page, players)
    clock += 1000

def press(button):
    global clock
    events.append((clock, button, button.lower()))
    events.append((clock + 200, 'NONE', 'release'))
    clock += 1000

capture('root')
press('A'); capture('career-one', 'CAREER', 1)
press('RIGHT'); capture('career-two', 'CAREER', 2)
press('DOWN'); capture('career-country', 'CAREER', 2)
press('DOWN'); capture('career-skill', 'CAREER', 2)
press('DOWN'); capture('career-start', 'CAREER', 2)
press('DOWN'); capture('career-wrap', 'CAREER', 2)
press('LEFT'); capture('career-one-again', 'CAREER', 1)
press('B'); press('DOWN'); press('A'); capture('rally-one', 'RALLY', 1)
press('RIGHT'); capture('rally-two', 'RALLY', 2)
press('DOWN'); capture('rally-skill', 'RALLY', 2)
press('DOWN'); capture('rally-start', 'RALLY', 2)
press('DOWN'); capture('rally-wrap', 'RALLY', 2)
press('LEFT'); capture('rally-one-again', 'RALLY', 1)
press('B'); press('UP'); press('A'); capture('career-return', 'CAREER', 1)
press('RIGHT'); capture('career-two-before-time-trial', 'CAREER', 2)
press('B'); press('DOWN'); press('DOWN'); press('A'); capture('time-trial', 'TIME TRIAL', 1)
press('B'); press('UP'); press('A'); capture('rally-two-restored', 'RALLY', 2)
press('B'); press('UP'); press('A'); capture('career-two-restored', 'CAREER', 2)
route = output / 'menu-summary-route.txt'
route.write_text(''.join(f'{t} {b} NONE {label}\n' for t,b,label in events), encoding='ascii')
prefix = output / 'menu-summary'
result = subprocess.run([str(runner.resolve()), '--headless-v27', str(rom.resolve()),
                         str((clock + 1000) // 1000), str(route.resolve()), str(prefix.resolve())],
                        capture_output=True, text=True)
(output / 'menu-summary-console.txt').write_text(result.stdout + result.stderr, encoding='utf-8')
if result.returncode:
    raise SystemExit(result.stdout + result.stderr)
rom_bytes = rom.read_bytes()

def word(data, offset):
    return int.from_bytes(data[offset:offset+2], 'little')

def small(s):
    return [ord(c)-64 if 'A' <= c <= 'Z' else ord(c)-48+27 if c.isdigit()
            else 37 if c == ':' else 0 for c in s]

def big(c):
    if c == ' ': return 128
    n = ord(c)-65
    return (130+2*n if n < 7 else 160+2*(n-7) if n < 15
            else 192+2*(n-15) if n < 23 else 224+2*(n-23))

lines = []
for index, (label, page, players) in checks.items():
    base = f'{prefix}.event-{index:03d}'
    ram = pathlib.Path(base + '.wram.bin').read_bytes()
    vram = pathlib.Path(base + '.vram.bin').read_bytes()
    assert (2 if word(ram, 0x1F04) else 1) == players, label + ': player count'
    x = (32-len(page)*2)//2
    assert [word(vram, (2*32+x+2*n)*2) for n in range(len(page))] == list(map(big,page)), label + ': title overwritten'
    if page == 'TIME TRIAL':
        assert [word(vram,(17*32+4+n)*2) for n in range(5)] == small('NAME:'), label
        assert word(vram,(18*32+15)*2) == 0, 'Career/Rally separator leaked into Time Trial'
        lines.append('PASS ' + label)
        continue
    setup = []
    for p, x in enumerate((3,18)):
        ca, ga, co = ((0x1F8F,0x1F7A,0x1F76),(0x1FAC,0x1F97,0x1F93))[p]
        car = ('CANNIBAL','SIDEWINDER','RAZOR','WEASEL')[word(ram,ca)&3]
        gear = 'MANUAL' if word(ram,ga)|word(ram,ga+2) else 'AUTO'
        control = next(('TYPE '+chr(65+t) for t in range(4)
                        if ram[co:co+4] == rom_bytes[0x6C656+t*16:0x6C65A+t*16]), 'TYPE ?')
        values = [car,gear,control] if p == 0 or players == 2 else ['NONE']*3
        for y, value in zip((18,20,22,24), ['PLAYER '+str(p+1)] + values):
            off = (11-len(value))//2
            expected = [0]*off + small(value) + [0]*(11-off-len(value))
            actual = [word(vram,(y*32+x+n)*2) for n in range(11)]
            assert actual == expected, f'{label}: P{p+1} row {y}: {actual} != {expected}'
        setup.append('/'.join(values))
    lines.append(f'PASS {label}: P1 {setup[0]}; P2 {setup[1]}')
report = '\n'.join(lines) + '\n'
(output / 'menu-summary-verification.txt').write_text(report, encoding='utf-8')
print(report, end='')
