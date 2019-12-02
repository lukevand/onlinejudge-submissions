import sys
lines = [line.strip().split() for line in sys.stdin.readlines()[1:]]
bdays = [(line[0], int(line[1]), int(line[2]), int(line[3])) for line in lines]
bdays.sort(key=lambda x: (-x[3], -x[2], -x[1]))
print(bdays[0][0], bdays[-1][0], sep='\n')
