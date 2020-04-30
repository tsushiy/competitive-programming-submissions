n, m = list(map(int, input().split()))
a = list(map(int, input().split()))
res = n - sum(a)
if res >= 0:
  print(res)
else:
  print(-1)