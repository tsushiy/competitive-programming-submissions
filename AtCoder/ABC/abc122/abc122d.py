n = int(input())
mod = 10**9+7

dp = [[[[0 for i in range(4)] for i in range(4)] for i in range(4)] for i in range(n+1)]

for i in range(4):
  for j in range(4):
    for k in range(4):
      dp[0][i][j][k] = 1

for i in range(4):
  for j in range(4):
    for m in range(4):
      if i==2 and j==0 and m==1:
        dp[0][m][i][j] = 0
      elif i==0 and j==2 and m==1:
        dp[0][m][i][j] = 0
      elif i==1 and j==0 and m==2:
        dp[0][m][i][j] = 0
      elif i==2 and k==0 and m==1:
        dp[0][m][i][j] = 0
      elif j==2 and k==0 and m==1:
        dp[0][m][i][j] = 0

# A=0, C=1, G=2, T=3
for l in range(1, n+1):
  for m in range(4):
    for i in range(4):
      for j in range(4):
        for k in range(4):
          if i==2 and j==0 and m==1:
            dp[l][m][i][j] = 0
          elif i==0 and j==2 and m==1:
            dp[l][m][i][j] = 0
          elif i==1 and j==0 and m==2:
            dp[l][m][i][j] = 0
          elif i==2 and k==0 and m==1:
            dp[l][m][i][j] = 0
          elif j==2 and k==0 and m==1:
            dp[l][m][i][j] = 0
          else:
            dp[l][m][i][j] += dp[l-1][i][j][k]%mod

print(dp[n][3][3][3]%mod)