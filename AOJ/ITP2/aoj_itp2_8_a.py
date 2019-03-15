n = int(input())
d = dict()
for i in range(n):
  q = input().split()
  if q[0]=="0":
    d[q[1]] = int(q[2])
  elif q[0]=="1":
    print(d[q[1]])