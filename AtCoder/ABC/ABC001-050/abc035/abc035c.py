n, q = list(map(int, input().split()))
a = [0]*(n+1)

for i in range(q):
  l, r = list(map(int, input().split()))
  a[l-1] += 1
  a[r] -= 1

for i in range(1, n):
  a[i] += a[i-1]

a = [a[i]%2 for i in range(n)]
for i in range(n):
  print(a[i], end="")
print()