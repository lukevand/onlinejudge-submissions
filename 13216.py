import sys
for line in (pow(66, int(line), 100) for line in sys.stdin.readlines()[1:]): print(line)
