import re
import sys

for line in sys.stdin.readlines():
    print(len(re.findall(r'[a-zA-Z]+', line)))

