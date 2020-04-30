n = int(input())
a = list(map(int, input().split()))
ans = 0
cur = 1

if 1 not in a:
  print(-1)
  exit()

for e in a:
  if e == cur:
    cur += 1
  else:
    ans += 1
print(ans)