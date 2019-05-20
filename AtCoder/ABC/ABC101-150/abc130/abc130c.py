w, h, x, y = list(map(int, input().split()))
ans = w*h/2
if w/2==x and h/2==y:
  flag = 1
else:
  flag = 0
print(ans, flag)