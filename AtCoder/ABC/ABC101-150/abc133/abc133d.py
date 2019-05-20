n = int(input())
a = list(map(int, input().split()))
b = [-a[i] if i%2 else a[i] for i in range(n)]
c = [a[i] if i%2 else -a[i] for i in range(n)]
ans = []
for i in range(1, n):
  b[i] += b[i-1]
  c[i] += c[i-1]
for i in range(n):
  if n%2==0:
    ans.append(b[n-1]-b[i-1]+c[i-1])
  else:
    ans.append(abs(c[n-1]-c[i-1]+b[i-1]))
print(*ans)