n = int(input())
a = list(map(int, input().split()))
ans = 0

for i in range(n):
  for j in range(30):
    if a[i]%2 == 0:
      a[i] = a[i]//2
      ans += 1

print(ans)