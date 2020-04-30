n, m = list(map(int, input().split()))
a = list(map(int, input().split()))
s = sum(a)
cnt = 0
for e in a:
  if e >= s * (1/(4*m)):
    cnt += 1
if cnt >= m:
  print("Yes")
else:
  print("No")