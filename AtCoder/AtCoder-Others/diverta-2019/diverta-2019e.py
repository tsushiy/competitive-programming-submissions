n = int(input())
a = list(map(int, input().split()))
s = [0 for i in range(n)]
s[0] = a[0]
for i in range(1, n):
  s[i] = s[i-1]^a[i]

MOD = 10**9+7
dp0 = [1 for i in range(1<<20)]
dp1 = [0 for i in range(1<<20)]
cnt = [0 for i in range(1<<20)]
z = 0
for i in range(n):
  if s[i]==0:
    z += 1
  else:
    dp0[s[i]] = (dp0[s[i]]+dp1[s[i]]*(z-cnt[s[i]]))%MOD
    dp1[s[i]] = (dp1[s[i]]+dp0[s[i]])%MOD
    cnt[s[i]] = z

if s[n-1]:
  print(dp0[s[n-1]])
else:
  ans = pow(2, z-1, MOD)
  for i in range(1<<20):
    ans += dp1[i]
  print(ans)