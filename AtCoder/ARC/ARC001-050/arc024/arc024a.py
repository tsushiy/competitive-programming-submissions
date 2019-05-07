L, R = list(map(int, input().split()))
l = list(map(int, input().split()))
r = list(map(int, input().split()))
ans = 0
for i in range(10, 41):
  ans += min(l.count(i), r.count(i))
print(ans)