n, x = list(map(int, input().split()))
a = list(map(int, input().split()))
ans = 0
for i in range(n):
  if x&1:
    ans+=a[i]
  x >>= 1
print(ans)