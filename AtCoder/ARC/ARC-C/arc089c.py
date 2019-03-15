n = int(input())
t1, x1, y1 = map(int, input().split())
if t1<x1+y1 or (x1+y1+t1)%2==1:
  print("No")
  exit()
for i in range(n-1):
  t2, x2, y2=map(int, input().split())
  if t2<x2+y2 or (abs(x2-x1)+abs(y2-y1))>t2-t1 or (x2+y2+t2)%2==1:
    print("No")
    exit()
print("Yes")