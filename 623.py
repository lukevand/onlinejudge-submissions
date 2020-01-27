import sys
import math
for line in sys.stdin.readlines():
    print(line.strip(), '!', sep='')
    print(math.factorial(int(line)))
