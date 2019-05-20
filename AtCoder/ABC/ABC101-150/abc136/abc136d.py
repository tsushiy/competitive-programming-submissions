s = input()
a = [0 for i in range(len(s))]

cnt = 0
for i in range(len(s)):
  if s[i]=='R':
    cnt += 1
    if i==len(s)-1:
      a[i] += cnt
  else:
    if i>0:
      a[i-1] += cnt
    cnt = 0

cnt = 0
for i in range(len(s)-1, -1, -1):
  if s[i]=='L':
    cnt += 1
    if i==0:
      a[i] += cnt
  else:
    if i<len(s)-1:
      a[i+1] += cnt
    cnt = 0

for i in range(len(s)-1):
  if s[i:i+2]=="RL":
    t1 = (a[i]+1)//2 + a[i+1]//2
    t2 = a[i]//2 + (a[i+1]+1)//2
    a[i], a[i+1] = t1, t2
print(*a)