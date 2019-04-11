a, k = list(map(int, input().split()))
ans = 0
if k==0:
  print(2*10**12-a)
else:
  while True:
    if a>=2*10**12:
      print(ans)
      break
    a += 1+k*a
    ans += 1