n, d = map(int, input().split())
a, b, c = 0, 0, 0
while d%2==0:
  a+=1
  d/=2
while d%3==0:
  b+=1
  d/=3
while d%5==0:
  c+=1
  d/=5
if d>1:
  print(0)
  exit()

dp = [[[[0 for _ in range(c+1)] for _ in range(b+1)] for _ in range(a+1)] for _ in range(n+1)]

dp[0][0][0][0]=1

for i in range(n):
  for j in range(a+1):
    for k in range(b+1):
      for l in range(c+1):
        if dp[i][j][k][l] == 0:
          continue
        else:
          dp[i+1][j][k][l] += dp[i][j][k][l]/6
          dp[i+1][min(a, j+1)][k][l] += dp[i][j][k][l]/6
          dp[i+1][j][min(b, k+1)][l] += dp[i][j][k][l]/6
          dp[i+1][min(a, j+2)][k][l] += dp[i][j][k][l]/6
          dp[i+1][j][k][min(c, l+1)] += dp[i][j][k][l]/6
          dp[i+1][min(a, j+1)][min(b, k+1)][l] += dp[i][j][k][l]/6
print(dp[n][a][b][c])