n, m = list(map(int, input().split()))
s = {e for e in list(map(int, input().split()))}
d = {1:2, 2:5, 3:5, 4:4, 5:5, 6:6, 7:3, 8:7, 9:6}
dp = [-1 for i in range(n+1)]
dp[0] = 0
for i in range(1, n+1):
  for e in s:
    if i-d[e]>=0 and dp[i-d[e]]>=0:
      dp[i] = max(dp[i], dp[i-d[e]]+1)

ans = ""
j = n
for i in range(dp[n]):
  for e in sorted(s, reverse=True):
    if j-d[e]>=0 and dp[j]-1==dp[j-d[e]]:
      ans += str(e)
      j -= d[e]
      break
print(ans)