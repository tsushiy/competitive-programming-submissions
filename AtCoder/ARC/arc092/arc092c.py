n = int(input())
s, t = [], []
for i in range(n):
  a, b = list(map(int, input().split()))
  s.append((a, b))
for i in range(n):
  c, d = list(map(int, input().split()))
  t.append((c, d))
s.sort(key=lambda x:x[1])
t.sort()

ans = 0
for i in range(n):
  for j in range(n-1, -1, -1):
    if s[j]==None:
      continue
    if s[j][0]<t[i][0] and s[j][1]<t[i][1]:
      ans+=1
      s[j] = None
      break
print(ans)