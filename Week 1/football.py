NUM_PLAYERS_DANGEROUS = 7
    
positions = input()
if "1"*NUM_PLAYERS_DANGEROUS in positions or "0"*NUM_PLAYERS_DANGEROUS in positions:
    print("YES")
else:
    print("NO")