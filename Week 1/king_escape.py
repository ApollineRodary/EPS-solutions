n = int(input())

queen = list(map(int, input().split()))
king = list(map(int, input().split()))
destination = list(map(int, input().split()))

if king[0] < queen[0] < destination[0] or king[0] > queen[0] > destination[0] \
    or king[1] < queen[1] < destination[1] or king[1] > queen[1] > destination[1]:
    print("NO")
else:
    print("YES")