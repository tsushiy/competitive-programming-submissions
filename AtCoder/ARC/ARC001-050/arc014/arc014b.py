n = int(input())
turn = True
s = set()
last = ""
for i in range(n):
  w = input()
  if (last != "" and last != w[0]) or w in s:
    if turn:
      print("LOSE")
    else:
      print("WIN")
    exit()
  s.add(w)
  last = w[-1]
  turn = not turn
print("DRAW")