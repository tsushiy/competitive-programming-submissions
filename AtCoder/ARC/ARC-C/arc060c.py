# O(N^3*max(x))解法
# PyPyなら間に合う

n, a = list(map(int, input().split()))
x = list(map(int, input().split()))
m = max(max(x), a)
dp = [[[0 for _ in range(n*m+1)] for _ in range(n+1)] for _ in range(n+1)]
dp[0][0][0] = 1

for j in range(1, n+1):
  for k in range(n+1):
    for s in range(n*m+1):
      if s<x[j-1]:
        dp[j][k][s] = dp[j-1][k][s]
      elif k>=1:
        dp[j][k][s] = dp[j-1][k][s]+dp[j-1][k-1][s-x[j-1]]
ans = 0
for i in range(1, n+1):
  ans += dp[n][i][i*a]
print(ans)