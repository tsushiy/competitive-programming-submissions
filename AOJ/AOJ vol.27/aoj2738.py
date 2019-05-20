n = int(input())
s = [input() for i in range(n)]
cnt = 0
for e in s:
  if e=="A":
    cnt += 1
  else:
    cnt -= 1
  if cnt<0:
    print("NO")
    exit()
if cnt==0:
  print("YES")
else:
  print("NO")