import sys
input = sys.stdin.readline

n, q = map(int, input().split())
array = list(map(int, input().split()))

# counts[k]: how many times a[k] should be counted, where a is the array once sorted so to maximise the sum
# counts has size n+1 for convenience but counts[n] should be 0
counts = [0 for _ in range(n+1)]

# Get each query, add 1 for every beginning of query, remove 1 for every end of query
for _ in range(q):
    l, r = map(lambda x: int(x)-1, input().split())
    counts[l] += 1
    counts[r+1] -= 1

# Get cumulative totals (this is so much better than doing it in n² omg)
for i in range(n):
    counts[i+1] += counts[i]

# Associate highest values in array to indexes counted most often
# Also I think I know a bunch of people that might scream at me for how unpythonic that line is but I love it
sys.stdout.write(str(sum(x*count for count, x in zip(sorted(counts[:-1]), sorted(array)))) + '\n')