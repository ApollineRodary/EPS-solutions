n, k = map(int, input().split())

def grade(entry):
    """
    Grades an entry based on its number of occurrences and its recency
    An entry with more occurrences has a lower score
    A more recent entry with as many occurrences has a lower score
    """
    return - occurrences[entry]*1000000 - recency[entry]

occurrences = {}
recency = {}

for i in range(3*n):
    entry = input()
    if entry not in occurrences:
        occurrences[entry] = 1
    else:
        occurrences[entry] += 1
    recency[entry] = i

top_entries = [entry for entry in sorted(occurrences.keys(), key=grade)]
how_many_entries = min(k, len(occurrences.keys()))
print("\n".join(top_entries[:how_many_entries]))