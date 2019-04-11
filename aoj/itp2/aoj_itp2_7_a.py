n = int(input())
s = set()
for i in range(n):
  q = list(map(int, input().split()))
  if q[0]==0:
    s.add(q[1])
    print(len(s))
  else:
    if q[1] in s:
      print(1)
    else:
      print(0)