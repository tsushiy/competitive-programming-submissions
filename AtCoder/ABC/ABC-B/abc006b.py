MOD = 10007
n = int(input())
t = [0]*(10**6+1)
t[3] = 1
for i in range(4, n+1):
  t[i] = (t[i-1]+t[i-2]+t[i-3])%MOD
print(t[n])