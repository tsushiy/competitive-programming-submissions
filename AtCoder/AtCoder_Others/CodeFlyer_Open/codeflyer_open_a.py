n = int(input())
ans = float("INF")
for i in range(n):
  cnt = 0
  p = input()
  for j in p[::-1]:
    if j=="0":
      cnt+=1
    else:
      break
  ans=min(ans, cnt)
print(ans)