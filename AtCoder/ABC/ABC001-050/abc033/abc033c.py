import sys
sys.setrecursionlimit(100000)
s = input()
a = s.split("+")
ans = 0
for e in a:
  if eval(e)>0:
    ans += 1
print(ans)