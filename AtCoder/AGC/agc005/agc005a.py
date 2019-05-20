x = input()
ans = len(x)
s = 0
t = 0
for i in range(len(x)):
  if x[i] == "S":
    s += 1
  else:
    if s>0:
      s -= 1
      t -= 1
      ans -= 2
    t += 1
print(ans)