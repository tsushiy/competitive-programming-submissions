n, k = list(map(int, input().split()))
r = list(map(int, input().split()))
r.sort(reverse=True)
ans = 0
cur = 2
for i in range(k):
  ans += r[i]/cur
  cur *= 2
print(ans)