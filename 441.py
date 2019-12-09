import itertools
import sys
lines = [[int(x) for x in line.split()[1:]] for line in sys.stdin.readlines()[:-1]]
n = len(lines)
for i, line in enumerate(lines):
    for comb in itertools.combinations(line, 6):
        print(*comb)
    if (i != n-1):
        print()

