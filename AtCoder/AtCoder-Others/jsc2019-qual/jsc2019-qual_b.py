n, k = list(map(int, input().split()))
a = list(map(int, input().split()))
MOD = 10**9+7
d = [[0, 0] for i in range(n)]
for i in range(n):
  cur1 = 0
  cur2 = 0
  for j in range(i):
    if a[i]>a[j]:
      cur2 += 1
  for j in range(i+1, n):
    if a[i]>a[j]:
      cur1 += 1
      cur2 += 1
  d[i] = [cur1, cur2]
ans = 0
for i in range(n):
  ans = (ans+d[i][0]*k)%MOD
  t = ((k*(k-1))//2)%MOD
  ans = (ans+d[i][1]*t)%MOD
print(ans)