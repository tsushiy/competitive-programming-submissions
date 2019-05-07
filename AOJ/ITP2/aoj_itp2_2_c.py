# maxヒープを使うときはキーを入れるときにマイナスをかけてやる
from heapq import heappop, heappush
n, q = list(map(int, input().split()))
a = [[] for i in range(n)]
for _ in range(q):
  q = list(map(int, input().split()))
  if q[0]==0:
    heappush(a[q[1]], -1*q[2])
  elif q[0]==1:
    if len(a[q[1]])>0:
      print(-1*a[q[1]][0])
  elif q[0]==2:
    if len(a[q[1]])>0:
      heappop(a[q[1]])