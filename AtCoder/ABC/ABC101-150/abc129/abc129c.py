n, m = list(map(int, input().split()))
MOD = 1000000007

dp = [0 for i in range(n+5)]
dp[0] = 1
a = set()
for i in range(m):
  t = int(input())
  a.add(t)

for i in range(n):
  if i+2 not in a:
    dp[i+2] = (dp[i+2]+dp[i])%MOD
  if i+1 not in a:
    dp[i+1] = (dp[i+1]+dp[i])%MOD

print(dp[n]%MOD)