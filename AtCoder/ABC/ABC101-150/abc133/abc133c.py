l, r = list(map(int, input().split()))
ans = 1e20
for i in range(l, min(r, l+2020)):
  for j in range(i+1, min(r+1, i+1+2020)):
    ans = min(ans, (i%2019)*(j%2019)%2019)
print(ans)