m, d = list(map(int, input().split()))
ans = 0
for mm in range(1, m+1):
  for dd in range(1, d+1):
    d1 = dd%10
    d2 = dd//10
    if d1>=2 and d2>=2 and d1*d2==mm:
      ans += 1
print(ans)