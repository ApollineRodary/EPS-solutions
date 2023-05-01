testcases = int(input())

for _ in range(testcases):
    n = int(input())
    s = input()

    last = ' '
    count = 0
    for (i, si) in enumerate(s):
        if si == last:
            count += 1
        else:
            last = si
            count = 1
        print(i+2-count, end=" ")
    print()
