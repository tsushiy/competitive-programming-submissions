n = int(input())
s = 0
for i in range(10):
  for j in range(10):
    s += i*j
t = s-n
for i in range(10):
  for j in range(10):
    if i*j==t:
      print(i, "x", j)