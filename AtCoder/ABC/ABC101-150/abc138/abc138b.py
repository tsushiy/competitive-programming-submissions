n = int(input())
a = list(map(int, input().split()))
ans = 0
for e in a:
  ans += 1/e
print(1/ans)