s = input()
from string import ascii_lowercase
t = set(ascii_lowercase)
a = t-set(s)
if len(a)==0:
  print("None")
else:
  print(sorted(a)[0])