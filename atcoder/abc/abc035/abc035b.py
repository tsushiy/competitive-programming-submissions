s = input()
t = int(input())
x, y, q = 0, 0, 0
for ele in s:
  if ele=="L":
    x-=1
  elif ele=="R":
    x+=1
  elif ele=="U":
    y+=1
  elif ele=="D":
    y-=1
  else:
    q+=1
if t==1:
  ans = abs(x)+abs(y)+q
else:
  if abs(x)+abs(y)>=q:
    ans = abs(x)+abs(y)-q
  else:
    ans = (q-abs(x)+abs(y))%2
print(ans)