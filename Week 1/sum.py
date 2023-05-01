tests = int(input())
    
for test in range(tests):
    a, b, c = map(int, input().split())
    
    if a==b+c or b==a+c or c==a+b:
        print("Yes")
    else:
        print("No")