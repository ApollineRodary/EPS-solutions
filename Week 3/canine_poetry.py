for _ in range(int(input())):
    poem = input()
    last = None
    before_last = None
    changed = 0
    for c in poem:
        if c==last or c==before_last:
            changed += 1
            c = None
        before_last, last = last, c
    print(changed)