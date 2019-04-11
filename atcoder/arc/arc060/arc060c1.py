# O(N^2*max(x))解法

n, a = list(map(int, input().split()))
x = list(map(int, input().split()))
y = [ele-a for ele in x]
m = n*max(a, max(x))
dp = [[0 for _ in range(2*m+1)]for _ in range(n+1)]
dp[0][m] = 1
for j in range(1, n+1):
  for t in range(2*m+1):
    if t-y[j-1]<0 or 2*m<t-y[j-1]:
      dp[j][t] = dp[j-1][t]
    elif 0<=t-y[j-1]<=2*m:
      dp[j][t] = dp[j-1][t] + dp[j-1][t-y[j-1]]
print(dp[n][m]-1)