n, k = list(map(int, input().split()))
a = list(map(int, input().split()))
dp = [[-1 for i in range(2)] for i in range(51)]
dp[50][0] = 0
for i in range(49, -1, -1):
  mask = 1<<i
  ones = 0
  for e in a:
    if e&mask:
      ones+= 1
  for e in a:
    if dp[i+1][0]!=-1:
      if k&mask:
        dp[i][0] = max(dp[i][0], dp[i+1][0] + mask*(n-ones))
        dp[i][1] = max(dp[i][1], dp[i+1][0] + mask*ones)
      else:
        dp[i][0] = max(dp[i][0], dp[i+1][0] + mask*ones)
    if dp[i+1][1]!=-1:
      dp[i][1] = max(dp[i][1], dp[i+1][1] + mask*max(ones, n-ones))
print(max(dp[0][0], dp[0][1]))