n = int(input())
ans = float("INF")
for i in range(1, n+1):
  d = abs(n//i-i)
  r = n%i
  ans = min(ans, d+r)
print(ans)