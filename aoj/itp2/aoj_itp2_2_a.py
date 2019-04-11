n, q = list(map(int, input().split()))
a = [[] for i in range(n)]
for _ in range(q):
  q = list(map(int, input().split()))
  if q[0]==0:
    a[q[1]].append(q[2])
  elif q[0]==1:
    if len(a[q[1]])>0:
      print(a[q[1]][-1])
  elif q[0]==2:
    if len(a[q[1]])>0:
      a[q[1]].pop()