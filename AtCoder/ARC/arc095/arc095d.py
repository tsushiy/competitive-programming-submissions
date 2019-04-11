N = int(input())
a = list(map(int, input().split()))
a.sort()
n = a[-1]
r = 0
for i in range(N-1):
  if min(a[i], n-a[i])>min(r, n-r):
    r = a[i]
print(n, r)