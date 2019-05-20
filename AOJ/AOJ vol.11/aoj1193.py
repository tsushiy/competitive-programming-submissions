while True:
  h = int(input())
  if h==0:
    break
  board = [list(map(int, input().split())) for i in range(h)]
  ans = 0

  while True:
    tans = 0
    for y in range(h):
      begin, end = 0, 0
      for x in range(1, 5):
        if board[y][x]==board[y][x-1]:
          end = x
        elif end-begin+1>=3:
          break
        else:
          begin = x
          continue
      if end-begin+1>=3:
        tans += board[y][begin]*(end-begin+1)
        for x in range(begin, end+1):
          board[y][x] = 0

    move = True
    while move:
      move = False
      for y in range(1, h):
        for x in range(5):
          if board[y][x]==0 and board[y-1][x]==0:
            continue
          elif board[y][x]==0:
            board[y][x], board[y-1][x] = board[y-1][x], board[y][x]
            move = True
    if tans>0:
      ans += tans
    else:
      break
  print(ans)