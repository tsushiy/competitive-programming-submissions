s = input()
t = input()
m = "atcoder@"
for a, b in zip(s, t):
  if a==b or (a=="@" and b in m) or (b=="@" and a in m):
    continue
  else:
    print("You will lose")
    exit()
print("You can win")