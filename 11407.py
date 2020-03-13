memo = [100000 for _ in range(101)]
squares = [x**2 for x in range(1, 11)]
for i in squares:
    memo[i] = 1

def solve(i, n):
    if i == n:
        return
    for m in squares:
        memo[m]
