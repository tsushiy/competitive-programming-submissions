def intersect(x1, y1, r1, x2, y2, r2):
  d1 = (x1-x2)**2+(y1-y2)**2
  d2 = (r1+r2)**2
  return d2 > d1


while True:
  n = int(input())
  if n==0:
    break

  xyrc = [0 for i in range(n)]
  on = [0 for i in range(n)]
  dp = [-1 for i in range(1<<n)]
  dp[0] = 0
  ans = 0

  for i in range(n):
    x, y, r, c = list(map(int, input().split()))
    xyrc[i] = [x, y, r, c]
    for j in range(i):
      if intersect(x, y, r, xyrc[j][0], xyrc[j][1], xyrc[j][2]):
        on[i] = on[i]|(1<<j)

  for i in range(1<<n):
    if dp[i]==-1:
      continue

    ans = max(ans, dp[i])

    for j in range(n-1):
      if i&(1<<j) or (i&on[j])!=on[j]:
        continue
      for k in range(j+1, n):
        if i&(1<<k) or (i&on[k])!=on[k] or xyrc[j][3]!=xyrc[k][3]:
          continue
        next_ = i|(1<<j)|(1<<k)
        dp[next_] = max(dp[next_], dp[i]+2)

  print(ans)