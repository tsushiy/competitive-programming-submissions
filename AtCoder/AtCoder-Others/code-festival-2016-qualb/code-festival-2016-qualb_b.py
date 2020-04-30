n, a, b = list(map(int, input().split()))
s = input()
x = 0
y = 1
for e in s:
  if e == 'a':
    if x < a+b:
      print("Yes")
      x += 1
    else:
      print("No")
  elif e == 'b':
    if x < a+b and y <= b:
      print("Yes")
      x += 1
    else:
      print("No")
    y += 1
  else:
    print("No")