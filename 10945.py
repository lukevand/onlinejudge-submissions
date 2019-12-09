import sys
import re
for i in [re.sub(r'[?.!, ]','',l.strip().lower()) for l in sys.stdin.readlines()[:-1]]:
    print(("Uh oh..","You won't be eaten!")[i==i[::-1]])

