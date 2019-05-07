n, w = map(int, input().split())
vw = [list(map(int, input().split())) for _ in range(n)]
dp = [[0]*(w+1) for _ in range(n+1)]

for i in range(n-1, -1, -1):
  for j in range(w+1):
    if j<vw[i][1]:
      dp[i][j] = dp[i+1][j]
    else:
      dp[i][j] = max(dp[i+1][j], dp[i+1][j-vw[i][1]]+vw[i][0])

print(dp[0][w])