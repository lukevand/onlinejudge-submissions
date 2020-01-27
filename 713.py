import sys
lines = sys.stdin.readlines()[1:]
for line in lines:
    x, y = line.split()
    x = x.rstrip('0')[::-1]
    y = y.rstrip('0')[::-1]
    print(str(int(x)+int(y)).rstrip('0')[::-1])
