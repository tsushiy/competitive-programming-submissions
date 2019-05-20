while True:
  m, n = list(map(int, input().split()))
  if m==0:
    break
  num = [0 for i in range(7368792)]
  for i in range(n):
    while num[m]==1:
      m += 1
    j = 1
    while m*j<7368792:
      num[m*j] = 1
      j += 1

  while num[m]==1:
    m += 1
  print(m)