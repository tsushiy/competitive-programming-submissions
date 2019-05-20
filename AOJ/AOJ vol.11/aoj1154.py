p = [1]*300010
p[0]=p[1]=0
for i in range(2, 300010):
  if not(i%7==1 or i%7==6):
    p[i] = 0

for i in range(2, 300010):
  if p[i]:
    for j in range(i*2, 300010, i):
      p[j] = 0

doyososu = []
for i in range(2, 300010):
  if p[i]:
    doyososu.append(i)

while True:
  n = int(input())
  if n==1:
    break
  ans = []
  for e in doyososu:
    if n%e==0:
      ans.append(e)
  print(n, ":", sep="", end=" ")
  print(*ans)