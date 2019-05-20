s = input()
from collections import Counter
c = Counter(s)
flag = True
if c["S"]>0 and c["N"]==0:
  flag = False
if c["N"]>0 and c["S"]==0:
  flag = False
if c["W"]>0 and c["E"]==0:
  flag = False
if c["E"]>0 and c["W"]==0:
  flag = False
if flag:
  print("Yes")
else:
  print("No")