n = int(input())
a = list(map(int, input().split()))
ans = -1e9
for i in range(n):
  ao = -1e9
  ao_j = -1
  ta = 0
  for j in range(n):
    ao_t = 0
    if i==j: continue
    l = min(i, j)
    r = max(i, j)
    for k in range(l+1, r+1, 2):
      ao_t += a[k]
    if ao_t>ao:
      ao = ao_t
      ao_j = j
  l = min(i, ao_j)
  r = max(i, ao_j)
  for k in range(l, r+1, 2):
    ta += a[k]
  ans = max(ans, ta)
print(ans)