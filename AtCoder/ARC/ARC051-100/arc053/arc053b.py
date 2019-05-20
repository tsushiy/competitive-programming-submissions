from collections import Counter
s = input()
d = dict(Counter(s))
base = 0
rem = 0
for k in d.keys():
  if d[k]%2==1:
    base += 1
    d[k] -= 1
  rem += d[k]
if base==0:
  print(rem)
else:
  cnt = (rem//2)//base
  print(1+cnt*2)