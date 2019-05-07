MOD = 10**9+7
MAX = 3*(10**5)+2

fact, inverse = [0]*(MAX), [0]*(MAX)
fact[0], inverse[0] = 1, 1
for i in range(1, MAX):
  fact[i] = (fact[i-1]*i)%MOD
  inverse[i] = pow(fact[i], MOD-2, MOD)

def mod_comb(n, r):
  if n<r or n==0: return 0
  if r==0: return 1
  return (((fact[n]*inverse[r])%MOD)*inverse[n-r])%MOD