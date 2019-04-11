n = int(input())
s = ""
for i in range(n):
  s+=input()
t = s.count("R")
a = s.count("B")
if t>a:
  print("TAKAHASHI")
elif t<a:
  print("AOKI")
else:
  print("DRAW")