n, k = list(map(int, input().split()))
a = list(map(int, input().split()))
acc = [0]*n
acc[0] = a[0]
for i in range(1, n):
  acc[i] = acc[i-1]+a[i]
ans = acc[k-1]
for i in range(1, n-k+1):
  ans += acc[i+k-1]-acc[i-1]
print(ans)