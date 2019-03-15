while True:
  h, w = list(map(int, input().split()))
  if h==w==0:
    break
  for i in range(h):
    for j in range(w):
      if (i+j)%2==0:
        print("#", end="")
      else:
        print(".", end="")
    print()
  print()