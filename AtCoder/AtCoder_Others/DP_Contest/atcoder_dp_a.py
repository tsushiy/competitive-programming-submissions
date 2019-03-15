n = int(input())
p = list(map(int, input().split()))

dp = [0]*10001
dp[0] = 1

for ele in p:
  for i in range(10000, -1, -1):
    if dp[i]==1:
      dp[i+ele]=1

ans = 0
for ele in dp:
  ans+=ele
print(ans)