n, k = list(map(int, input().split()))
ans = 0
a = [0]*k
for i in range(1, n+1):
  a[i%k] += 1

ans += a[0]**3
if k%2==0:
  ans += a[k//2]**3
print(ans)