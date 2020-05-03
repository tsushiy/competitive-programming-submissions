n, k = list(map(int, input().split()))
v = [0 for i in range(n)]
for i in range(k):
  d = int(input())
  a = list(map(int, input().split()))
  for j in range(d):
    v[a[j]-1] += 1
ans = 0
for i in range(n):
  if v[i] == 0:
    ans += 1
print(ans)