while True:
  h, w = list(map(int, input().split()))
  if h==w==0:
    break
  for i in range(h):
    print("#"*w)
  print()