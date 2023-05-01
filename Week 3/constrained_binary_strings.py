n = int(input())
a = [[0]*i + list(map(int, input().split())) for i in range(n)]

rangeinc = lambda x, y: range(x, y+1)

NO_CONSTRAINTS = 0
ALL_THE_SAME = 1
BOTH_DIGITS = 2

# count[i][k]: number of strings of length i+1 satisfying local constraints and such that the kth letter is the last 1 in the string
# k can be 0, in which case it refers to a string of only 0s

count = [[0 for k in range(n+1)] for i in range(n)]

def getConstraints(i, j):
    return a[i-1][j-1]

def getCount(i, k):
    return count[i-1][k]

def setCount(i, k, x):
    count[i-1][k] = x

# Count one letter strings

if getConstraints(1, 1) != BOTH_DIGITS:
    setCount(1, 0, 1)
    setCount(1, 1, 1)
else:
    setCount(1, 0, 0)
    setCount(1, 1, 0)

# Count i+1 letter strings for all i < n

for i in range(1, n):
    # Counting strings with i+1 0s (either 0 or 1)
    for k in rangeinc(1, i+1):
        if getConstraints(k, i+1) == BOTH_DIGITS:
            break
    else:
        setCount(i+1, 0, getCount(i, 0))
    
    # Counting strings of length i+1 with last 1 at position k, k <= i
    for k in rangeinc(1, i):
        canCount = True
        for j in rangeinc(1, k):
            if getConstraints(j, i+1) == ALL_THE_SAME:
                canCount = False
                break
        for j in rangeinc(k+1, i+1):
            if getConstraints(j, i+1) == BOTH_DIGITS:
                canCount = False
                break
        if canCount:
            setCount(i+1, k, getCount(i, k))
    
    # For symmetry reasons, there are as many strings of length i+1 that end with 1 as there are strings of length i+1 that end with 0
    setCount(i+1, i+1, sum([getCount(i+1, k) for k in rangeinc(0, i)]))

print(sum([getCount(n, k) for k in rangeinc(0, n)]) % 998244353)