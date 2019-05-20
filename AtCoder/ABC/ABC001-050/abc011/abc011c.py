n = int(input())
ng = {int(input()) for i in range(3)}
cnt = 0
if n in ng:
  print("NO")
  exit()

while cnt < 100:
  if n-3 not in ng and n-3>=0:
    n = n-3
  elif n-2 not in ng and n-2>=0:
    n = n-2
  elif n-1 not in ng and n-1>=0:
    n = n-1
  cnt += 1
if n==0:
  print("YES")
else:
  print("NO")