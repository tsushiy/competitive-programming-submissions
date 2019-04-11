n, c = list(map(int, input().split()))
x = [0]*(n+1)
v = [0]*(n+1)
f = [(0, 0)]*(n+1)
frev = [(0, 0)]*(n+1)
g = [(0, 0)]*(n+1)
grev = [(0, 0)]*(n+1)

for i in range(1, n+1):
  x[i], v[i] = list(map(int, input().split()))

for i in range(1, n+1):
  xt, vt = x[i], v[i]
  f[i] = (xt, f[i-1][1]+vt)
  if g[i-1][0]>f[i-1][1]+vt-xt:
    g[i] = g[i-1]
  else:
    g[i] = (f[i-1][1]+vt-xt, xt)
for i in range(1, n+1):
  xt, vt = x[n-i+1], v[n-i+1]
  frev[i] = (c-xt, frev[i-1][1]+vt)
  if grev[i-1][0]>frev[i-1][1]+vt-(c-xt):
    grev[i] = grev[i-1]
  else:
    grev[i] = (frev[i-1][1]+vt-(c-xt), (c-xt))

ans = 0
for i in range(0, n+1):
  if i==0:
    ans = max(ans, g[n][0])
  else:
    ans = max(ans, g[i][0], grev[i][0], frev[i][1]-frev[i][0]+g[n-i][0]-min(frev[i][0], g[n-i][1]))
print(ans)