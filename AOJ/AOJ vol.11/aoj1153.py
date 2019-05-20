while True:
  n, m = list(map(int, input().split()))
  if n==0:
    break

  a = [int(input()) for i in range(n)]
  b = [int(input()) for i in range(m)]
  sa = sum(a)
  sb = sum(b)
  a.sort()
  b.sort()

  ta, tb = 1e9, 1e9
  for i in range(n):
    for j in range(m):
      if (a[i]-b[j])*2==sa-sb:
        if ta+tb>a[i]+b[j]:
          ta, tb = a[i], b[j]

  if ta==1e9:
    print(-1)
  else:
    print(ta, tb)