a, b, c, d = list(map(int, input().split()))
if b<c or d<a:
  print(0)
else:
  print(min(b, d)-max(a, c))