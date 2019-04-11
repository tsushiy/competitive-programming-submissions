n = int(input())
a = list(map(int, input().split()))
if sum(a)%n!=0:
  print(-1)
else:
  ans = 0
  q = 0
  m = sum(a)//n
  for i in range(n):
    if a[i]+q>m:
      q += a[i]-m
      ans += 1
    elif a[i]+q<m:
      q -= m-a[i]
      ans += 1
    else:
      q = 0
  print(ans)