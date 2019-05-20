n = int(input())
a = [0]
at = list(map(int, input().split()))
a.extend(at)
b = [0]
bt = list(map(int, input().split()))
b.extend(bt)
b.append(0)
ans = 0

for i in range(1, n+2):
  if a[i]>=b[i-1]:
    ans += b[i-1]
    a[i] -= b[i-1]
    b[i-1] = 0
  else:
    ans += a[i]
    b[i-1] -= a[i]
    a[i] = 0
  if a[i]>=b[i]:
    ans += b[i]
    a[i] -= b[i]
    b[i] = 0
  else:
    ans += a[i]
    b[i] -= a[i]
    a[i] = 0

print(ans)
