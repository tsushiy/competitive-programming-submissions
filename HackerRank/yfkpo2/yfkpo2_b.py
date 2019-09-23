s = input()
a = [0]*len(s)
for i in range(len(s)):
  a[i] = ord(s[i])-ord("A")+1
b = [0]*(len(s)-1)
for i in range(len(s)-1):
  b[i] = a[i]+a[i+1]
ans = 1
for e in b:
  ans *= e
print(ans)