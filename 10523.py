import sys

for line in sys.stdin.readlines():
    N, A = list(map(int, line.split()))
    print(sum(i*A**i for i in range(1, N+1)))
