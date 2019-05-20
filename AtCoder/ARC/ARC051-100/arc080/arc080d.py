h, w = list(map(int, input().split()))
n = int(input())
a = list(map(int, input().split()))
b = [[0 for i in range(w)] for j in range(h)]
top = 0
bot = h-1
left = 0
right = w-1
x = 0
y = 0
flag = 0

for i in range(n):
  cnt = a[i]
  while cnt>0:
    b[y][x] = i+1
    cnt -= 1
    if flag==0 and x==left and y==bot:
      x += 1
      left += 1
      flag = (flag+1)%4
    elif flag==1 and x==right and y==bot:
      y -= 1
      bot -= 1
      flag = (flag+1)%4
    elif flag==2 and x==right and y==top:
      x -= 1
      right -= 1
      flag = (flag+1)%4
    elif flag==3 and x==left and y==top:
      y += 1
      top += 1
      flag = (flag+1)%4
    elif flag == 0:
      y += 1
    elif flag == 1:
      x += 1
    elif flag == 2:
      y -= 1
    elif flag == 3:
      x -= 1
for row in b:
  print(*row)