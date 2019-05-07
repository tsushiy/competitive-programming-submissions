n = int(input())
s = [int(input()) for i in range(n)]
s.sort()
b = [ele%10 for ele in s]
if not any(b):
  print(0)
  exit()

ans = sum(s)
if ans%10==0:
  for i in range(n):
    if s[i]%10:
      ans -= s[i]
      break
print(ans)