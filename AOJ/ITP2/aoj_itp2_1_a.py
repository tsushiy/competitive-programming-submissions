n = int(input())
a = []
for _ in range(n):
  q = list(map(int, input().split()))
  if q[0]==0:
    a.append(q[1])
  elif q[0]==1:
    print(a[q[1]])
  elif q[0]==2:
    a.pop()