testcases = int(input())

for _ in range(testcases):
    n = int(input())
    
    scores_self = list(map(int, input().split()))
    scores_ilya = list(map(int, input().split()))

    scores_self.sort(reverse=True)
    scores_ilya.sort(reverse=True)

    counted_stages = n - n//4
    uncounted_stages = n//4

    # Counted scores ranked from best to worst
    scores_self_counted = scores_self[:counted_stages]
    scores_ilya_counted = scores_ilya[:counted_stages]
    
    # Uncounted scores ranked from worst to best
    scores_self_uncounted = scores_self[counted_stages:][::-1]
    scores_ilya_uncounted = scores_ilya[counted_stages:][::-1]

    total_score_self = sum(scores_self_counted)
    total_score_ilya = sum(scores_ilya_counted)

    additional_stages = 0

    # Best case scenario to catch up with Ilya is I score 100 every time and she always scores 0
    while total_score_self < total_score_ilya:
        additional_stages += 1
        if (n+additional_stages) % 4 == 0:
            # If the same number of stages are to be counted, replace my worst counted score with a 100 should any non-100 result be counted
            if scores_self_counted:
                total_score_self -= scores_self_counted.pop()
                total_score_self += 100
        
        else:
            # If one more stage is to be counted, add 100 to my score and add Ilya's best uncounted result to her score should any nonzero result be left uncounted
            total_score_self += 100
            if scores_ilya_uncounted:
                total_score_ilya += scores_ilya_uncounted.pop()
    
    print(additional_stages)