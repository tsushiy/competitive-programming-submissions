n = int(input())
a = list(map(int, input().split()))
cnt1, cnt2, cnt4 = 0, 0, 0
for i in range(n):
  t = 0
  while a[i]%2==0:
    a[i] //= 2
    t += 1
  if t==0:
    cnt1 += 1
  elif t==1:
    cnt2 += 1
  else:
    cnt4 += 1
if cnt2>=1:
  cnt1 += 1
if cnt1<=cnt4+1:
  print("Yes")
else:
  print("No")