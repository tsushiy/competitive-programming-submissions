n, m = list(map(int, input().split()))
ab = []
for i in range(m):
  a, b = list(map(int, input().split()))
  ab.append((a, b))
ab.sort(key=lambda x:x[1])

ans = 0
max_ = 0
for ele in ab:
  if ele[0]>=max_:
    max_ = ele[1]
    ans += 1
print(ans)