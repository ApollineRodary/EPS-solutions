import sys

m, n = map(int, input().split())

# Figure out p
p = []
for _ in range(n):
    print(1)
    sys.stdout.flush()
    # If answer is 1, p_i is 1, otherwise p_i is 0
    answer = int(input())
    if answer==0:
        quit()
    p.append(answer==1)


# Figure out distance
a = 1
b = m
i = 0
while(True):
    guess = (a+b)//2
    print(guess)
    sys.stdout.flush()
    answer = int(input())
    answer_is_correct = p[i]

    if answer==-2:
        quit()
    
    if answer==0:
        quit()
    
    if (answer==-1 and answer_is_correct) or (answer==1 and not answer_is_correct):
        b = guess
    else:
        a = guess+1

    i += 1
    i %= n