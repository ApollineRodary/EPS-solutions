n, k = map(int, input().split())
s = input()

available_stage_weights = sorted(map(lambda c: ord(c) - ord('a') + 1, s))

total_weight = 0
total_size = 0
last_added_weight = -1

for stage_weight in available_stage_weights:
    if stage_weight > last_added_weight+1:
        total_weight += stage_weight
        total_size += 1
        last_added_weight = stage_weight
        if total_size == k:
            print(total_weight)
            break
else:
    print(-1)