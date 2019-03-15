h, w = map(int, input().split())
s = [input() for _ in range(h)]
flag = 0
dx = [-1, 0, 1]
dy = [-1, 0, 1]

for i in range(h):
  for j in range(w):
    f = 0
    if s[i][j] == "#":
      for dx_ in dx:
        for dy_ in dy:
          if (dx_==0 and dy_!=0) or (dx_!=0 and dy_==0):
            nx, ny = j+dx_, i+dy_
            if 0<=nx<w and 0<=ny<h:
              if s[ny][nx] == "#":
                f = 1
      if f == 0:
        flag = 1
if flag:
  print("No")
else:
  print("Yes")