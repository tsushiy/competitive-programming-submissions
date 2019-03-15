while True:
  h, w = list(map(int, input().split()))
  if h==w==0:
    break
  print("#"*w)
  for i in range(h-2):
    print("#"+"."*(w-2)+"#")
  print("#"*w)
  print()