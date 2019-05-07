from itertools import accumulate
n = int(input())
a = list(map(int, input().split()))
b = list(accumulate(a))
ll, rr = 0, 2
ans = float("INF")

for i in range(1, n-2):
  while True:
    p = b[ll]
    q = b[i]-b[ll]
    r = b[rr]-b[i]
    s = b[n-1]-b[rr]
    lt = abs(p-q)
    rt = abs(r-s)
    if abs(b[ll+1]-(b[i]-b[ll+1]))<lt:
      ll+=1
    elif abs((b[rr+1]-b[i])-(b[n-1]-b[rr+1]))<rt:
      rr+=1
    else:
      break
  ans = min(ans, abs(max(p, q, r, s)-min(p, q, r, s)))
print(ans)