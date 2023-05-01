import sys
import math
input = sys.stdin.readline
print = lambda x: sys.stdout.write(str(x) + "\n")

testcases = int(input())
TERMS = 5

for _ in range(testcases):
    n = int(input())
    numbers = list(map(int, input().split()))
    numbers.sort()

    # Get minimal and maximal numbers from the array. The best product is a product of 5 of these 10 numbers.
    if len(numbers)>10:
        candidates = numbers[:TERMS] + numbers[-TERMS:]
    else:
        candidates = numbers

    # max_products[i][j] = max product of i terms among the j smallest numbers
    max_products = [[-math.inf for i in range(len(candidates)+1)] for j in range(TERMS+1)]
    min_products = [[math.inf for i in range(len(candidates)+1)] for j in range(TERMS+1)]

    for i in range(len(candidates)):
        max_products[0][i] = 1
        min_products[0][i] = 1
    
    for i in range(TERMS):
        max_products[i+1][i+1] = candidates[i] * max_products[i][i]
        min_products[i+1][i+1] = candidates[i] * min_products[i][i]

    for i in range(TERMS):
        for j in range(i+1, len(candidates)):
            x = candidates[j]

            max_products[i+1][j+1] = max(
                max_products[i+1][j],
                (x * max_products[i][j]) if x>0 else (x * min_products[i][j])
            )

            min_products[i+1][j+1] = min(
                max_products[i+1][j],
                (x * max_products[i][j]) if x<0 else (x * min_products[i][j])
            )
    
    print(max_products[-1][-1])