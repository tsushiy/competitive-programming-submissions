h, w = list(map(int, input().split()))
if h == 1 or w == 1:
  print(1)
elif h*w % 2 == 1:
  print(h*w//2+1)
else:
  print(h*w//2)