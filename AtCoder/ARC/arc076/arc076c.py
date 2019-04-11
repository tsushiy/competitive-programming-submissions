n, m = list(map(int, input().split()))

MOD = 10**9+7
MAX = max(n, m)+2
fact = [0]*(MAX)
fact[0] = 1
for i in range(1, MAX):
  fact[i] = (fact[i-1]*i)%MOD

if abs(n-m)>1:
  ans = 0
else:
  if n==m:
    ans = fact[n]*fact[m]*2%MOD
  else:
    ans = fact[n]*fact[m]%MOD
print(ans)