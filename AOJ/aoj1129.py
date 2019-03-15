while True:
  n, r = map(int, input().split())
  if n==0 and r==0:
    break

  yama = [i for i in range(n, 0, -1)]
  for _ in range(r):
    p, c = map(int, input().split())
    up, bottom = [], []
    up.extend(yama[p-1:p+c-1])
    up.extend(yama[:p-1])
    bottom.extend(yama[p+c-1:])
    up.extend(bottom)
    yama = up[:]
  print(yama[0])