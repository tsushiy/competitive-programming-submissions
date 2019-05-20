n, k = list(map(int, input().split()))
v = list(map(int, input().split()))
ans = 0

from heapq import heappush, heappop
for i in range(1, k+1): #i個取り出す
  for j in range(0, i+1): #左からj個取り出す
    minus = []
    l = min(n, j)
    r = min(n-l, i-l)
    cur = 0
    for ll in range(l):
      cur += v[ll]
      if v[ll]<0:
        heappush(minus, v[ll])
    for rr in range(r):
      cur += v[n-rr-1]
      if v[n-rr-1]<0:
        heappush(minus, v[n-rr-1])
    rm = k-l-r
    while rm>0 and len(minus)>0:
      rm -= 1
      cur -= heappop(minus)
    ans = max(ans, cur)
print(ans)