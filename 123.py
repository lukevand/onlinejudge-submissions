import sys

lines = [line.strip() for line in sys.stdin.readlines()]
mid = 0
for i, el in enumerate(lines):
    if el == "::":
        mid = i
        break

ignore = set(lines[:mid])
titles = [line.lower() for line in lines[mid+1:]]
result = []

for j, title in enumerate(titles):
    for i, word in enumerate(title.split()):
        if word not in ignore:
            result.append((word.upper(), j, i, title.lower()))

result.sort()
for word, _, i, title in result:
    titleSplit = title.split()
    print(*titleSplit[:i], word, *titleSplit[i+1:])
