import datetime

n = int(input())
for _ in range(n):
    line = input().strip()
    print(line)
    date = datetime.datetime.strptime(line, "%m%d%Y")
    delta = datetime.timedelta(weeks=40)
    birthDate = date + delta
    if datetime.date(
