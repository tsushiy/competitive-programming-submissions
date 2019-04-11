a, b, c = list(map(int, input().split()))
if a+b>=c:
  ans = b+c
else:
  ans = (a+b)+b+1
print(ans)