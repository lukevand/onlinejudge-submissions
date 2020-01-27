import sys
for line in sys.stdin.readlines()[1:]:
    try:
        eval(line)
        print("Yes")
    except SyntaxError as e:
        print("No")
