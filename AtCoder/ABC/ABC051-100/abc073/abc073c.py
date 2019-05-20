n = int(input())
ans = set()
for i in range(n):
  a = int(input())
  if a in ans:
    ans.remove(a)
  else:
    ans.add(a)
print(len(ans))