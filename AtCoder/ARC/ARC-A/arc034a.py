n = int(input())
ans = 0
for i in range(n):
  a, b, c, d, e = list(map(int, input().split()))
  ans = max(ans, a+b+c+d+e*110/900)
print(ans)