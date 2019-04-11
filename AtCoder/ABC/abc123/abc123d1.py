x, y, z, k = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]
c = [int(x) for x in input().split()]

a.sort(reverse=True)
b.sort(reverse=True)
c.sort(reverse=True)

d = [e1+e2 for e1 in a for e2 in b]
d.sort(reverse=True)
d = d[:k]

e = [e1+e2 for e1 in d for e2 in c]    
e.sort(reverse=True)

for i in range(k):
  print(e[i])