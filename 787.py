import sys
from math import inf
lines = sys.stdin.readlines()
for line in lines:
    nums = [int(x) for x in line.split()][:-1]
    best = -inf
    bestPos = -inf; bestNeg = inf
    if len(nums) == 0:
        break
    for i in nums:
        # print(bestPos, bestNeg, best)
        if i > 0:
            bestPos = max(i, i*bestPos)
            bestNeg = min(i, i*bestNeg)
        elif i < 0:
            oldBestPos = bestPos
            bestPos = bestNeg*i
            bestNeg = min(oldBestPos*i, i)
        else:
            bestPos = -inf; bestNeg = inf
            best = max(best, 0)

        best = max(bestPos, best)
        if bestNeg != inf:
            best = max(bestNeg, best)

    print(best)


