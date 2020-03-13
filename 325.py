import sys
import re

for line in sys.stdin.readlines()[:-1]:
    line = line.strip()
    if not re.search(r'[\.e]', line, re.IGNORECASE):
        print(line, "is illegal.")
        continue
    m = re.match(r' *[-+]?\d+(\.\d+)?(e[-+]?\d+)? *$', line, re.IGNORECASE)
    if m:
        print(line, "is legal.")
    else:
        print(line, "is illegal.")
