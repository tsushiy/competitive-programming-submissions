import math
while True:
  r, n = map(int, input().split())
  if r==0 and n==0:
    break
  else:
    b = [0]*41
    t = [float("INF")]*41

    for _ in range(n):
      x1, x2, y = map(int, input().split())
      x1, x2 = x1+20, x2+20
      for i in range(x1, x2):
        b[i] = max(b[i], y)
    b[20+r], b[20-r-1] = float("INF"), float("INF")

    for i in range(20-r, 20+r+1):
      t[i] = min(b[i], b[i-1])+r-math.sqrt(r**2-(i-20)**2)

    print(min(t))
