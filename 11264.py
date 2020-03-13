import bisect
import sys

def withdraw(x, c, t):
    if (x == 0):
        return t
    i = bisect.bisect_right(moneys, x)
    t.append(moneys[i-1])
    return withdraw(x-moneys[i-1], c+1, t)

lines = sys.stdin.readlines()[2::2]
for line in lines:
    moneys = list(map(int, line.split()))
    best = 1
    if len(line.split()) == 1:
        print(1)
        continue
    # x = [len(list(set(withdraw(k, 0, [])))) for k in range(0, 2*moneys[-1])]
    x = len(list(set(withdraw(sum(moneys), 0, []))))
    print(x)
    # print(max(x))
