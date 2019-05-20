while True:
  n, w = list(map(int, input().split()))
  if n==0:
    break
  v = [int(input()) for i in range(n)]
  h = [0 for i in range(100)]
  ma = 0
  mi = 1e9
  for i in range(n):
    h[v[i]//w] += 1
    ma = max(ma, v[i]//w)
    mi = min(mi, v[i]//w)
  sm = ma-mi
  h = [h[i]/max(h) for i in range(100)]
  ans = 0.01
  for i in range(mi, ma):
    ans += (sm-i+mi)/(sm+mi)*h[i]
  print(ans)