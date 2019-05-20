n = int(input())
a = list(map(int, input().split()))
b = set(a)
c = sorted(list(b))
if len(b)==1 and c[0]==0:
  print("Yes")
  exit()
elif n%3!=0:
  print("No")
  exit()
elif len(b)==2:
  if c[0]==0 and a.count(c[0])==n//3 and a.count(c[1])==(n//3)*2:
    print("Yes")
    exit()
elif len(b)==3:
  p, q, r = c[0], c[1], c[2]
  if p^q==r or q^r==p or r^p==q:
    if a.count(c[0])==n//3 and a.count(c[1])==n//3 and a.count(c[2])==n//3:
      print("Yes")
      exit()
print("No")