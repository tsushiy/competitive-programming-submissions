from string import ascii_lowercase
from collections import defaultdict
d = defaultdict(int)
s = ""
while True:
  try:
    s += input()
  except EOFError:
    break
for ele in s:
  d[ele.lower()] += 1
for c in ascii_lowercase:
  print(c+" : "+str(d[c]))