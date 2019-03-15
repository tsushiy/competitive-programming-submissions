n = int(input())
t = [int(input()) for i in range(n)]
ans = float("INF")
for i in range(2**n):
  t1, t2 = 0, 0
  for j in range(n):
    if (i>>j)&1:
      t1+=t[j]
    else:
      t2+=t[j]
  ans = min(ans, max(t1, t2))
print(ans)