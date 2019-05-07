w = input()
t = []
for i in range(len(w)):
  if w[i] in t:
    t.remove(w[i])
  else:
    t.append(w[i])
if len(t) == 0:
  print("Yes")
else:
  print("No")