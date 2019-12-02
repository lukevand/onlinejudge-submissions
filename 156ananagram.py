line = input()
d = {}
while (line[0] != '#'):
    line = line.strip().split()
    for word in line:
        w = word.lower()
        sw = str(sorted(w))

        if sw not in d:
            d[sw] = []
        d[sw].append(word)

    line = input()

words = []
for key, val in d.items():
    if len(val) == 1:
        words.append(val[0])
print(*sorted(words), sep='\n')

