n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))
ans = 0
prev = -10
for e in a:
  ans += b[e-1]
  if e==prev+1:
    ans += c[prev-1]
  prev = e
print(ans)