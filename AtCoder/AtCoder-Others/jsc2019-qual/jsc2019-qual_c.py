n = int(input())
s = input()
MOD = 10**9+7

t = ["" for i in range(2*n)]
cntr, cntl = 0, 0

for i in range(2*n):
  if i%2==0 and s[i]=='B':
    t[i] = "R"
    cntr += 1
  elif i%2==0 and s[i]=='W':
    t[i] = "L"
    cntl += 1
  elif i%2==1 and s[i]=='B':
    t[i] = "L"
    cntl += 1
  elif i%2==1 and s[i]=='W':
    t[i] = "R"
    cntr += 1
if cntl!=cntr:
  print(0)
  exit()

cur = 1
rs, ls = 0, 0
for i in range(2*n-1, -1, -1):
  if t[i]=="L":
    ls += 1
  else:
    cur = (cur*(max(0, ls-rs)))%MOD
    rs += 1

MAX = 2*10**5+1
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

comb_build(MAX)
print((cur*fact[n])%MOD)