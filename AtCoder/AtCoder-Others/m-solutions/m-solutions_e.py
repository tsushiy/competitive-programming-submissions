MOD = 1000003
MAX = MOD
fact = [0 for i in range(MAX)]
inv = [0 for i in range(MAX)]
invfact = [0 for i in range(MAX)]

def comb_build(n):
  fact[0] = inv[0] = invfact[0] = 1
  fact[1] = inv[1] = invfact[1] = 1
  for i in range(2, n):
    fact[i] = fact[i-1]*i%MOD
    inv[i] = inv[MOD%i]*(MOD-MOD//i)%MOD
    invfact[i] = invfact[i-1]*inv[i]%MOD

def nCk(n, k):
  if n<k or n<0 or k<0:
    return 0
  return (((fact[n]*invfact[k])%MOD)*invfact[n-k])%MOD

comb_build(MAX)

q = int(input())
for i in range(q):
  x, d, n = list(map(int, input().split()))
  if x==0 or d==0:
    print(pow(x, n, MOD))
    continue

  x = x*pow(d, MOD-2, MOD)%MOD
  if x+n-1>=MOD:
    print(0)
  else:
    ans = pow(d, n, MOD)*fact[x+n-1]*invfact[x-1]%MOD
    print(ans)