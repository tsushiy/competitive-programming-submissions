t = int(input())
n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))

if m>n:
  print("no")
  exit()

cur = 0
flag = True
i = 0
j = 0
while i<n and j<m:
  if b[j]<a[i]:
    flag = False
    break
  else:
    if b[j]<=a[i]+t:
      j += 1
      i += 1
    else:
      i += 1
if j!=m:
  flag = False

if flag:
  print("yes")
else:
  print("no")