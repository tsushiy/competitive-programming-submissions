n = int(input())
a = []
c = 0
for _ in range(n):
  q = list(map(int, input().split()))
  if q[0]==0:
    a.insert(c, q[1])
  elif q[0]==1:
    c += q[1]
  elif q[0]==2:
    a.pop(c)
for ele in a:
  print(ele)