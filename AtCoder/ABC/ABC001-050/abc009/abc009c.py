n, k = list(map(int, input().split()))
s = input()
if k<=1:
  print(s)
  exit()

sl = list(s)
cur = 0
for i in range(n):
  mi = sl[i]
  mi_j = i
  for j in range(i+1, n):
    if mi>sl[j]:
      mi = sl[j]
      mi_j = j
  if mi_j != i:
    t = 0
    if sl[i] != s[i]:
      pass
    elif sl[mi_j] != s[i]:
      t += 1
    else:
      t -= 1
    if sl[mi_j] != s[mi_j]:
      pass
    elif sl[i] != s[mi_j]:
      t += 1
    else:
      t -= 1
    if cur+t>k:
      continue
    else:
      sl[i], sl[mi_j] = sl[mi_j], sl[i]
      cur += t
for e in sl:
  print(e, end='')
print()