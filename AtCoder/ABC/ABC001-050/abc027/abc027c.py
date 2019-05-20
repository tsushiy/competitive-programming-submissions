from math import log2
n = int(input())
depth = int(log2(n))+1
x = 1
turn = True
ans = True

if depth%2:
  while x<=n:
    if turn:
      x = x*2+1
    else:
      x = x*2
    turn = not turn
else:
  while x<=n:
    if turn:
      x = x*2
    else:
      x = x*2+1
    turn = not turn

if turn:
  print("Takahashi")
else:
  print("Aoki")