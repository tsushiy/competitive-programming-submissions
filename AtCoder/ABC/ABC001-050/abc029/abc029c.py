n = int(input())
from itertools import product
abc = "abc"
p = [abc for i in range(n)]
for e in product(*p):
  for k in e:
    print(k, end='')
  print()