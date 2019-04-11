s = input().split()
t = []
for ele in s:
  if ele=="Left":
    t.append("<")
  elif ele=="Right":
    t.append(">")
  else:
    t.append("A")
print(" ".join(t))