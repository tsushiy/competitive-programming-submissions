l = input()
MOD = 10**9+7
dp = [[0 for i in range(len(l)+1)] for i in range(2)]
dp[0][0] = 1

for i in range(1, len(l)+1):
  if l[i-1]=="0":
    dp[0][i] = (dp[0][i]+dp[0][i-1])%MOD
    dp[1][i] = (dp[1][i]+dp[1][i-1])%MOD
    dp[1][i] = (dp[1][i]+dp[1][i-1]*2)%MOD
  else:
    dp[0][i] = (dp[0][i]+dp[0][i-1]*2)%MOD
    dp[1][i] = (dp[1][i]+dp[0][i-1])%MOD
    dp[1][i] = (dp[1][i]+dp[1][i-1])%MOD
    dp[1][i] = (dp[1][i]+dp[1][i-1]*2)%MOD

print((dp[0][len(l)]+dp[1][len(l)])%MOD)