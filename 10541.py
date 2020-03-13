import sys

def f(i, space, total):
    if space < 0:
        return 0
    if i == K-1:
        if tiles[i] > space:
            return 0
        return space - tiles[i] + 1

    if total >= space:
        return 0

    if memo[i][space] != -1:
        # print(i, space, memo[i][space])
        return memo[i][space]

    count = 0
    for pad in range(1, space - tiles[i]):
        count += f(i+1, space - tiles[i] - pad, total-tiles[i])
    memo[i][space] = count
    return count

T = int(sys.stdin.readline())
for _ in range(T):
    line = sys.stdin.readline().split()
    N = int(line[0])
    K = int(line[1])
    if K == 0:
        print(1)
        continue
    tiles = list(map(int, line[2:]))
    memo = [[-1] * (N+1) for _ in range(K+1)]
    print(f(0, N, sum(tiles)))

