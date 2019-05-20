n = int(input())
a = [0]*6
for i in range(n):
  ma, mi = list(map(float, input().split()))
  if 35<=ma:
    a[0] += 1
  if 30<=ma<35:
    a[1] += 1
  if 25<=ma<30:
    a[2] += 1
  if 25<=mi:
    a[3] += 1
  if mi<0 and 0<=ma:
    a[4] += 1
  if ma<0:
    a[5] += 1
print(*a)