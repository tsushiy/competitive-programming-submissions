n = int(input())
a = []
m1 = -1
i1 = 0
m2 = -1
i2 = 1
for i in range(n):
  t = int(input())
  a.append(t)
  if t>m2:
    i2 = i
    m2 = t
  if m2>m1:
    i1, i2 = i2, i1
    m1, m2 = m2, m1
for i in range(n):
  if i!=i1:
    print(m1)
  else:
    print(m2)