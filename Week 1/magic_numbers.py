string = input()
    
buffer = ""
for c in string:
    if c not in "14":
        print("NO")
        break
    if c=="4":
        if buffer == "1":
            buffer = "14"
        elif buffer == "14":
            buffer = ""
        else:
            print("NO")
            break
    elif c=="1":
        buffer = "1"
else:
    print("YES")