n, h = list(map(int, input().split()))
a, b, c, d, e = list(map(int, input().split()))
ans = float("INF")
for i in range(n+1):
  y = (-i*(b+e)+n*e-h)/(d+e)
  j = max(0, int(y+1))
  cost = i*a + j*c
  manpuku = i*b+j*d-e*(n-i-j)+h
  ans = min(ans, cost)
print(ans)