import sys
import datetime

datetime.max = 999999999999999
print(datetime.MAXYEAR)
print(datetime.max)


line = map(int, sys.stdin.readline().split())
while True:
    days, d, m, y = line
    if y == 0:
        break
    date = datetime.date(y, m, d)
    delta = datetime.timedelta(days=days)
    print(delta)
    newdate = date + delta
    print("{} {} {}".format(newdate.day, newdate.month, newdate.year))
    line = map(int, sys.stdin.readline().split())

