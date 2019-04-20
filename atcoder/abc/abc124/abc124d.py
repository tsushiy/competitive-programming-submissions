n, k = list(map(int, input().split()))
s = input()

l = [0]
ans = 0

for i in range(1, n):
  if s[i-1]=="1" and s[i]=="0":
    l.append(i)
  if s[i-1]=="0" and s[i]=="1":
    l.append(i)

for i, e in enumerate(l):
  if s[e]=="0":
    if i+2*k>=len(l):
      ans = max(ans, n-e)
    else:
      ans = max(ans, l[i+2*k]-e)
  else:
    if i+2*k+1>=len(l):
      ans = max(ans, n-e)
    else:
      ans = max(ans, l[i+2*k+1]-e)
print(ans)