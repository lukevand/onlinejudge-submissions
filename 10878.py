import sys

for line in sys.stdin.readlines()[1:-1]:
    line = line.strip()
    line = line.strip('|')
    line = line[:5] + line[6:]
    total = 0
    for i, c in enumerate(reversed(line)):
        if c == 'o':
            total += 2**i
    sys.stdout.write(chr(total))

