n, d, k = list(map(int, input().split()))
lr = [list(map(int, input().split())) for i in range(d)]
for i in range(k):
  s, t = list(map(int, input().split()))
  j = 0
  if s<t:
    while s<t:
      if lr[j][0]<=s<=lr[j][1]:
        s = max(s, lr[j][1])
      j += 1
  else:
    while s>t:
      if lr[j][0]<=s<=lr[j][1]:
        s = min(s, lr[j][0])
      j += 1
  print(j)