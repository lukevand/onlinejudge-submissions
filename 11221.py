import sys
import re
import math
def f(line, sq):
    flip = line[::-1]
    if line != flip:
        return True

    news = []
    for i in range(sq):
        for j in range(sq):
            if line[j*sq + i] != flip[j*sq + i] or line[j*sq+i] != line[i*sq+j]:
                return True

    return False

for i, line in enumerate([re.sub(r'[.,?! ()]', '', l.strip()) for l in sys.stdin.readlines()[1:]], 1):
    print("Case #{}:".format(i))

    l = len(line)
    sq = int(math.sqrt(l))
    if (sq*sq != l or f(line, sq)):
        print("No magic :(")
    else:
        print(sq)


