from collections import defaultdict
n = int(input())
d = defaultdict(bool)
for i in range(n):
  q, s = input().split()
  if q=="insert":
    d[s] = True
  elif q=="find":
    if d[s]:
      print("yes")
    else:
      print("no")