n = int(input())
t, h = 0, 0
for i in range(n):
  a, b = input().split()
  if a<b:
    h += 3
  elif a>b:
    t += 3
  else:
    h += 1
    t += 1
print(t, h)