MOD = 10**9+7
n = int(input())
ans = 1
for i in range(1, n+1):
  ans = ans*i%MOD
print(ans)