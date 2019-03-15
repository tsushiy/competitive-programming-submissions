while True:
  n = int(input())
  if n==0:
    break
  s = list(map(int, input().split()))
  m = sum(s)/len(s)
  v = 0
  for ele in s:
    v += ((ele-m)**2)/len(s)
  print(v**0.5)