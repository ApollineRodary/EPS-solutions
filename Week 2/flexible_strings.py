import itertools

testcases = int(input())

def count_pairs(a, b, q):
    """Count (l, r) pairs such that a[l, r] = b[l, r] after modification of letters in q"""
    pairs = 0
    l = 0
    n = len(a)
    while l<n:
        r = l
        while r<n and (a[r]==b[r] or a[r] in q):
            r += 1
        pairs += (r-l)*(r-l+1)//2
        l = r+1
    return pairs

for _ in range(testcases):
    n, k = map(int, input().split())
    a = input()
    b = input()

    # We have no reason to consider Q having more letters than there are different letters in A that do not appear at the same position in B
    different = [0 for _ in range(26)]
    for (x, y) in zip(a, b):
        if x != y:
            different[ord(x) - ord('a')] = True
    k = min(sum(different), k)

    # q is the set of letters that appear in A at positions where they do not appear in B
    q = set()
    for i in range(26):
        if different[i]:
            q.add(chr(i + ord('a')))

    # We can now generate sets of k letters in q and see which offers the most pairs
    max_pairs = 0
    combinations = list(map(set, itertools.combinations(q, k)))
    for combination in combinations:
        pairs = count_pairs(a, b, combination)
        if pairs > max_pairs:
            max_pairs = pairs
    
    print(max_pairs)