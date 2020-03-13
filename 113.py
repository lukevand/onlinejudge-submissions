import sys
import math

lines = sys.stdin.readlines()

i = 0
while i < len(lines):
    n = int(lines[i])
    p = int(lines[i+1])
    print(round(p**(1/n)))
    i += 2
