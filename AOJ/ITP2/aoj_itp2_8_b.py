from collections import defaultdict
n = int(input())
d = defaultdict(int)
for i in range(n):
  q = input().split()
  if q[0]=="0":
    d[q[1]] = int(q[2])
  elif q[0]=="1":
    print(d[q[1]])
  elif q[0]=="2":
    d[q[1]] = 0