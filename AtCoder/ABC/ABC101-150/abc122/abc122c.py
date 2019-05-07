n, q = list(map(int, input().split()))
s = input()

a = [0 for i in range(n)]

for i in range(1, n):
  if s[i-1]=="A" and s[i]=="C":
    a[i]=a[i-1]+1
  else:
    a[i]=a[i-1]
    
for i in range(q):
  l, r = list(map(int, input().split()))
  print(a[r-1]-a[l-1])