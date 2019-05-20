s = [i*(i+1)*(i+2)//6 for i in range(190)]
dp1 = [0 for i in range(10**6)]
dp2 = [0 for i in range(10**6)]
for i in range(10**6):
  dp1[i] = dp2[i] = i
  j = 1
  while i>=s[j]:
    dp1[i] = min(dp1[i], dp1[i-s[j]]+1)
    if s[j]%2:
      dp2[i] = min(dp2[i], dp2[i-s[j]]+1)
    j += 1

while True:
  n = int(input())
  if n==0:
    exit()
  print(dp1[n], dp2[n])