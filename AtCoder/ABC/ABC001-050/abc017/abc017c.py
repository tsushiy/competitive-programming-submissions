n, m = list(map(int, input().split()))
a = [0]*(m+1)
b = 0
for i in range(n):
  l, r, s = list(map(int, input().split()))
  b += s
  a[l-1] += s
  a[r] -= s
acc = [0]*m
acc[0] = a[0]
for i in range(1, m):
  acc[i] = acc[i-1] + a[i]
print(b-min(acc))