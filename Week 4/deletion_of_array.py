import heapq, sys

input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    counts = {}
    for ai in a:
        counts[ai] = (counts[ai]+1) if ai in counts else 1

    h = []
    for count in counts.values():
        if count != 0:
            heapq.heappush(h, -count)
    while len(h)>2:
        a = -heapq.heappop(h)
        b = -heapq.heappop(h)
        c = -h[0]
        if (a-b)>=c:
            # Cancel out the two most frequent elements as much as possible if the most frequent element is to remain most frequent
            heapq.heappush(h, b-a)
        else:
            # Otherwise, cancel out until the most frequent element is as frequent as the third most frequent
            heapq.heappush(h, -c+1)
            heapq.heappush(h, a-b-c+1)
    if len(h)==2:
        print(h[1]-h[0])
    else:
        print(-h[0] if h else 0)