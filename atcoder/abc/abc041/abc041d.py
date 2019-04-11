n, m = map(int, input().split())
xy = [list(map(int, input().split())) for _ in range(m)]

dp = [0]*(1<<n)
dp[0] = 1
b = [0]*n

for i in range(len(xy)):
  b[xy[i][1]-1] |= 1<<(xy[i][0]-1)
  
for i in range(1<<n):
  for j in range(n):
    if (i>>j)&1 == 1:
      if b[j]&(i^(1<<j)) == b[j]:
        dp[i] += dp[i^(1<<j)]

print(dp[-1])