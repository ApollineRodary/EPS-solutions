import heapq

tests = int(input())

for test in range(tests):
    n, m = map(int, input().split())
    numbers = list(map(int, input().split()))
    new_numbers = list(map(int, input().split()))

    heapq.heapify(numbers)

    for new_number in new_numbers:
        heapq.heappop(numbers)
        heapq.heappush(numbers, new_number)
    
    print(sum(numbers))