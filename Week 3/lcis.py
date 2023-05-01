n = int(input())
u = list(map(int, input().split()))
m = int(input())
v = list(map(int, input().split()))

# lcis_length[j] = length of LCIS of u and v(1, ..., j)
lcis_length = [0 for _ in range(m)]

# previous[j] = index in v of second to last term in LCIS of u and v(1, ..., j)
previous = [0 for _ in range(m)]

for i, ui in enumerate(u):
    cis_length = 0
    p = None
    for j, vj in enumerate(v):
        if ui == vj and cis_length >= lcis_length[j]:
            # If the terms match, expand on the current LCIS
            lcis_length[j] = cis_length+1
            previous[j] = p
        
        elif ui > vj and cis_length < lcis_length[j]:
            # If u[i] < v[j] adding u[i] will cannot expand on LCIS of u(1, ..., i) and v(1, ..., j)
            # If u[i] > v[j] next matches of u[i] and v[j'] with j' > j may expand on a previous LCIS 
            cis_length = lcis_length[j]
            p = j

# Find end of LCIS and its length
length = 0
for i, l in enumerate(lcis_length):
    if l > length:
        length = l
        lcis_ends_at = i

# Backtrack to get full LCIS
lcis = []
if length>0:
    while (lcis_ends_at != None):
        lcis.append(v[lcis_ends_at])
        lcis_ends_at = previous[lcis_ends_at]

print(length)
print(" ".join(map(str, lcis[::-1])))