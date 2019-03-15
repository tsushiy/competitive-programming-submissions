cons = [ (1,3,5,4,2,6),
        (3,1,2,6,5,4),
        (1,5,4,2,3,6),
        (5,1,3,6,4,2),
        (1,4,2,3,5,6),
        (4,1,5,6,2,3),
        (1,2,3,5,4,6),
        (2,1,4,6,3,5),
 
        (6,3,2,4,5,1),
        (3,6,5,1,2,4),
        (6,2,4,5,3,1),
        (2,6,3,1,4,5),
        (6,4,5,3,2,1),
        (4,6,2,1,5,3),
        (6,5,3,2,4,1),
        (5,6,4,1,3,2),
 
        (3,5,1,2,6,4),
        (5,3,6,4,1,2),
        (5,4,1,3,6,2),
        (4,5,6,2,1,3),
        (4,2,1,5,6,3),
        (2,4,6,3,1,5),
        (2,3,1,4,6,5),
        (3,2,6,5,1,4)]
 
dic = {1:(0,1), 2:(1,0), 3:(0,-1), 4:(-1,0)}
 
def dice_set(t,f):
  for ele in cons:
    if ele[0]==t and ele[1]==f:
      return ele
 
 
def dice_turn(k, ele):
  if k == 1:
    t, f = ele[3], ele[0]
  elif k == 2:
    t, f = ele[4], ele[1]
  elif k == 3:
    t, f = ele[1], ele[5]
  elif k == 4:
    t, f = ele[2], ele[1]
  return dice_set(t,f)
 
 
while True:
  n = int(input())

  if n==0:
    break

  fields = [ [[0,0] for _ in range(30)] for i in range(30)]

  for i in range(n):
    t, f = map(int, input().split())
    dice = dice_set(t,f)

    x,y = 14,14

    count = 0
    while True:
      count +=1
      go = -1
      go_num = 0

      for k, v in dic.items():
        if dice[k] >= 4:
          dx,dy = v
          if fields[x+dx][y+dy][0] < fields[x][y][0]:
            if go_num < dice[k]:
              go = k
              go_num = dice[k]

      if go == -1:
        fields[x][y][0] += 1
        fields[x][y][1] = dice[0]
        break
      else:
        dice = dice_turn(go, dice)
        dx, dy = dic[go]
        x += dx
        y += dy

    ans = [0]*7
    for i in range(30):
      for j in range(30):
        ans[fields[i][j][1]]+= 1
 
    print(" ".join(map(str, ans[1:])))