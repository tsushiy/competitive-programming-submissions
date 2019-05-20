s = int(input())
t = {s}
m = 1
while True:
  if s%2:
    s = 3*s+1
  else:
    s //= 2
  m += 1
  if s in t:
    print(m)
    break
  t.add(s)
