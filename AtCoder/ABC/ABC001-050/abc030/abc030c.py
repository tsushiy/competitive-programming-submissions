from bisect import bisect_left
n, m = list(map(int, input().split()))
x, y = list(map(int, input().split()))
a = list(map(int, input().split()))
b = list(map(int, input().split()))
ans = 0
cur = 0
nowA = True
while True:
  if nowA:
    idx = bisect_left(a, cur)
    if idx==n:
      break
    cur = a[idx]+x
    nowA = False
  else:
    idx = bisect_left(b, cur)
    if idx==m:
      break
    ans += 1
    cur = b[idx]+y
    nowA = True
print(ans)