w = input()
v = "aiueo"
a = ""
for ele in w:
  if not ele in v:
    a += ele
print(a)