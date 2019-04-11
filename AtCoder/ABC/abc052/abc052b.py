n = int(input())
s = input()
x = 0
ans = 0
for ele in s:
  if ele=="I":
    x+=1
  else:
    x-=1
  ans = max(ans, x)
print(ans)