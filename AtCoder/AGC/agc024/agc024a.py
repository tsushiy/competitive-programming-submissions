a, b, c, k = map(int, input().split())

if k%2==0:
  ans=a-b
else:
  ans=b-a
if abs(ans)>1000000000000000000:
  print("Unfair")
else:
  print(ans)