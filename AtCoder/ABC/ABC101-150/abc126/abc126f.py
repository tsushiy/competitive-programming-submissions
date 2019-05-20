m, k = list(map(int, input().split()))

if m==1:
  if k==0:
    print("0 0 1 1")
  else:
    print(-1)
  exit()

if k>=2**m:
  print(-1)
  exit()

ans = []
for i in range(2**m):
  if i==k:
    continue
  ans.append(i)
ans.append(k)
for i in range(2**m-1, -1, -1):
  if i==k:
    continue
  ans.append(i)
ans.append(k)
print(*ans)