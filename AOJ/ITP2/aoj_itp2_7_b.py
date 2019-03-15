n = int(input())
s = set()
for i in range(n):
  q = list(map(int, input().split()))
  if q[0]==0:
    s.add(q[1])
    print(len(s))
  elif q[0]==1:
    if q[1] in s:
      print(1)
    else:
      print(0)
  else:
    if q[1] in s:
      s.remove(q[1])