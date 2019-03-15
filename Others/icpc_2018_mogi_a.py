while True:
  inp = input()
  if inp == '#':
    break
  else:
    inplist = list(inp.split())
    g = inplist[0]
    h, m, d = map(int, inplist[1:])

    if h>=32 or (h==31 and m>=5):
      print("?", h-30, m, d)
    else:
      print(g, h, m, d)
