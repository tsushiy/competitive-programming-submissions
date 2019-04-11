n, a, b = map(int, input().split())
s=[]
Max=0
Min=10**9
Sum=0
for i in range(n):
  s.append(int(input()))
  if Max<s[i]:
    Max=s[i]
  if Min>s[i]:
    Min=s[i]
  Sum+=s[i]
if Max==Min:
  print("-1")
  exit()
p=b/(Max-Min)
q=a-Sum*p/n
print(p, q)
