import time
n = int(input())
a = list(map(int, input().split()))

MAX = 210000
MOD = 1000000007

start = time.time()

fac = [0 for i in range(MAX)]
inv = [0 for i in range(MAX)]
sum_inv = [0 for i in range(MAX)]


def COMinit():
  fac[0] = 1
  fac[1] = 1
  inv[1] = 1
  sum_inv[0] = 0
  sum_inv[1] = 1
  for i in range(2, MAX):
    fac[i] = fac[i - 1] * i % MOD
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD
    sum_inv[i] = sum_inv[i - 1] + inv[i] % MOD


COMinit()
elapsed = time.time() - start
print(elapsed)
