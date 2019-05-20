while True:
  s = input()
  if s=="#":
    break

  g, y, m, d = s.split()
  y, m, d = int(y), int(m), int(d)
  if y>=32 or (y==31 and m>=5):
    g = "?"
    y -= 30
  print(g, y, m, d)