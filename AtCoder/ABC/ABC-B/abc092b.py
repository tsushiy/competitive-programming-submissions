n = int(input())
d, x = map(int, input().split())
ans = x
for _ in range(n):
  a = int(input())
  ans += len(range(1, d+1, a))
print(ans)