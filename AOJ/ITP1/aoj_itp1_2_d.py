w, h, x, y, r = list(map(int, input().split()))
if 0<=x-r and 0<=y-r and x+r<=w and y+r<=h:
  print("Yes")
else:
  print("No")