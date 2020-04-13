import itertools

memo = {}
memo[3] = 0


def f(n):
    if n in memo:
        return memo[n]

    if (n % 2) == 0:
        h = n//2 - 2
        re = f(n-1) + h*(h+1) + n//2 - 1
    else:
        h = n//2 - 1
        re = f(n-1) + h*(h+1)

    memo[n] = re
    return re


def verify(n):
    x = [len([(x, y, z) for x, y, z in itertools.combinations(
        range(1, i+1), 3) if x+y > z]) for i in range(3, n+1)]

    y = [f(x) for x in range(3, n+1)]

    print(y)
    print(x == y)


verify(15)
