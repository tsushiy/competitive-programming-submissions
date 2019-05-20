n = int(input())
a = list(map(int, input().split()))
c = [0 for i in range(n)]

for i in range(n, n//2, -1):
  if a[i-1]:
    c[i-1] = 1
for i in range(n//2, 1, -1):
  t = i
  tt = 0
  cnt = 1
  while t<=n:
    tt += c[t-1]
    cnt += 1
    t = i*cnt
  if (a[i-1]==1 and tt%2==0) or (a[i-1]==0 and tt%2==1):
    c[i-1] = 1

ttt = sum(c)
if (ttt%2==0 and a[0]==1) or (ttt%2==1 and a[0]==0):
  c[0] = 1
  ttt += 1
#print(c)
ans = []
for i in range(n):
  if c[i]:
    ans.append(i+1)
print(ttt)
if ttt:
  print(*ans)