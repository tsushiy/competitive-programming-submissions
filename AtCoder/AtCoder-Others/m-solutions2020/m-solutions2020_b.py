a, b, c = list(map(int, input().split()))
k = int(input())
while b <= a:
  b *= 2
  k -= 1
while c <= b:
  c *= 2
  k -= 1
if k >= 0:
  print("Yes")
else:
  print("No")