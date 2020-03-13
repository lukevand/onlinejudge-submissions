import itertools
import sys

def tobin(num, width):
    return '{0:0{width}b}'.format(num, width=width)

def bars(num, n):
    b = tobin(num, n)
    return len(list(itertools.groupby(b)))

def maxConseq(num, n):
    b = tobin(num, n)
    best = -1
    for k, g in itertools.groupby(b):
        m = len(list(g))
        best = max(best, m)
    return best

def generate(n, k, m):
    count = 0
    for i in range(int(2**(n-1)), 2**n+1):
        if bars(i, n) == k and maxConseq(i, n) <= m:
            count += 1
    return count
            # print('{0:0{width}b}'.format(i, width=n))


# for line in sys.stdin.readlines():
#     n, k, m = map(int, line.split())

# for i in range(1, 20):
#     print(i, generate(7, i, 3));
# print(generate(10,7,4), [generate(9, 7, i) for i in range(5)])
print(generate(7, 4, 7))
# for i in range(1,10):
#     for j in range(1,10):
#         k = 5
#         print(i, j, k, ':', generate(i, j, k))
