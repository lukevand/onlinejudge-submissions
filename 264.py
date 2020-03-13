import sys
import bisect

triangle_numbers = [1 + n*(n+1)//2 for n in range(5000)]

for line in sys.stdin.readlines():
    query = int(line)
    if query == 1:
        print("TERM {} IS {}/{}".format(1,1,1))
        continue
    index = bisect.bisect_left(triangle_numbers, query)-1
    n = (query - triangle_numbers[index])
    # print(index, n, triangle_numbers[index])
    if index % 2 == 0:
        start = index + 1
        end = 1

        start  -= n
        end += n

    else:
        end = index + 1
        start = 1

        end  -= n
        start += n

    if start == 0:
        start += 1
    if end == 0:
        end += 1
    print("TERM {} IS {}/{}".format(query, start, end))


