n, m = list(map(int, input().split()))
l = 1
r = n
for i in range(m):
  ll, rr = list(map(int, input().split()))
  l = max(l, ll)
  r = min(r, rr)
print(max(0, r-l+1))