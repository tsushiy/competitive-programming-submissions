n, m = list(map(int, input().split()))
t = [0 for i in range(m+1)]
for i in range(n):
  a = list(map(int, input().split()))
  for j in range(1, len(a)):
    t[a[j]] += 1
ans = 0
for i in range(1, m+1):
  if t[i]==n:
    ans += 1
print(ans)