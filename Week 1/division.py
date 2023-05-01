def division(rating: int) -> int:
    if rating >= 1900:
        return 1
    if rating >= 1600:
        return 2
    if rating >= 1400:
        return 3
    return 4
    
testcases = int(input())
    
for _ in range(testcases):
    print("Division", division(int(input())))