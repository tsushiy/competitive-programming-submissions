a, b, c = list(map(int, input().split()))
if a==b==c and a%2==1:
  print(0)
elif a==b==c and a%2==0:
  print(-1)
else:
  ans = 0
  while True:
    if a%2==1 or b%2==1 or c%2==1:
      break
    a, b, c = (b+c)//2, (a+c)//2, (a+b)//2
    ans += 1
  print(ans)