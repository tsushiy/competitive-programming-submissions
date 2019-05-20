from bisect import bisect_left
n, k = list(map(int, input().split()))
x = list(map(int, input().split()))

zero = bisect_left(x, 0)
rs = n-zero
ls = n-rs
ans = float("INF")

for i in range(min(k, rs)+1):
  if i==0:
    r = 0
  elif zero+i-1>n-1:
    continue
  else:
    r = x[zero+i-1]
  if i==k:
    l = 0
  elif zero-k+i<0:
    continue
  else:
    l = abs(x[zero-k+i])
  ans = min(ans, min(r*2+l, r+l*2))
print(ans)