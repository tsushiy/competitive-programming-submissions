n = int(input())
a = list(map(int, input().split()))
s = [0 for i in range(n)]
s[0] = a[0]
for i in range(1, n):
  s[i] = s[i-1]^a[i]

MOD = 10**9+7
dp = [[not j for i in range(1<<20)] for j in range(2)]
cnt = [0 for i in range(1<<20)]
z = 0
for i in range(n):
  if s[i]==0:
    z += 1
  dp[0][s[i]] = (dp[0][s[i]]+dp[1][s[i]]*(z-cnt[s[i]])%MOD)%MOD
  dp[1][s[i]] = (dp[1][s[i]]+dp[0][s[i]])%MOD
  cnt[s[i]] = z

if s[n-1]:
  print(dp[0][s[n-1]])
else:
  ans = pow(2, z-1, MOD)
  for i in range(1, 1<<20):
    ans = (ans+dp[1][i])%MOD
  print(ans)
