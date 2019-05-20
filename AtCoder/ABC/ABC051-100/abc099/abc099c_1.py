n = int(input())
dp = [1e9 for i in range(100001)]
dp[0] = 0
ans = n
yen = set()
for i in range(7):
  yen.add(6**i)
  dp[6**i] = 1
for i in range(6):
  yen.add(9**i)
  dp[9**i] = 1
for i in range(1, n+1):
  for e in yen:
    if i+e<=100000:
      dp[i+e] = min(dp[i+e], dp[i]+1)
print(dp[n])