x1, y1, r = list(map(int, input().split()))
x2, y2, x3, y3 = list(map(int, input().split()))
rr = r*r
if x2<=x1-r and y2<=y1-r and x1+r<=x3 and y1+r<=y3:
  print("NO")
else:
  print("YES")
if (x2-x1)**2+(y2-y1)**2<=rr and (x2-x1)**2+(y3-y1)**2<=rr and (x3-x1)**2+(y2-y1)**2<=rr and (x3-x1)**2+(y3-y1)**2<=rr:
  print("NO")
else:
  print("YES")