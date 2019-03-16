n, x = list(map(int, input().split()))
a = list(map(int, input().split()))

ans = 0
a.sort()
for i in range(n):
  if x<a[i]:
    break
  x -= a[i]
  ans += 1
if x>0 and ans==n:
  ans -= 1
print(ans)