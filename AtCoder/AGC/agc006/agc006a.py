n = int(input())
s = input()
t = input()
cnt = 0
if s==t:
  print(n)
  exit()
for i in range(n):
  if s[i:]==t[:-i]:
    cnt = max(cnt, n-i)
print(2*n-cnt)