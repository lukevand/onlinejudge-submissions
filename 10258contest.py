class Score:
    def __init__(self):
        self.problems = [0 for _ in range(10)]
        self.time_penalty = [0 for _ in range(10)]

T = int(input())
input()
for number in range(T):
    line = input().strip().split()
    score = {}
    stillGood = True
    while stillGood:
        c, problem, time, L = line
        c = int(c)
        problem = int(problem)
        time = int(time)
        if c not in score:
            score[c] = Score()

        if L == 'I' and score[c].problems[problem] == 0:
            score[c].time_penalty[problem] += 1

        elif L == 'C' and score[c].problems[problem] == 0:
            score[c].problems[problem] = time

        try:
            line = input().strip().split()
        except EOFError:
            stillGood = False
        if len(line) == 0:
            break

    t = []
    for key, val in score.items():
        time_pen = 0
        for a, b in zip(val.problems, val.time_penalty):
            time_pen += 20*(a>0)*b
        t.append((key, len([x for x in val.problems if x > 0]), time_pen+sum(val.problems)))
    t.sort(key=lambda x: (-x[1], x[2], x[0]))
    for x in t:
        print(*x)
    if number < T-1:
        print()

