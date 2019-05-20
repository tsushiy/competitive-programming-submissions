n, k = list(map(int, input().split()))
tk = [list(map(int, input().split())) for i in range(n)]
ans = 0
tk.sort(key=lambda x: -x[1])
max_ = [[i, 0, 0] for i in range(n+1)]
for i in range(n):
  if max_[tk[i][0]][1]<tk[i][1]:
    max_[tk[i][0]][1], max_[tk[i][0]][2] = tk[i][1], i
max_.sort(key=lambda x: -x[1])
for i in range(1, k+1):
  neta = set()
  have = set()
  cnt = 0
  cur = 0
  for j in range(i):
    if max_[j][1]>0:
      cur += max_[j][1]
      cnt += 1
      neta.add(max_[j][0])
      have.add(max_[j][2])
  for j in range(n):
    if j in have:
      continue
    if cnt==k:
      break
    if len(neta)<i:
      neta.add(tk[j][0])
      cnt += 1
      cur += tk[j][1]
    elif len(neta)==i and tk[j][0] in neta:
      cnt += 1
      cur += tk[j][1]
  ans = max(ans, cur+len(neta)**2)
print(ans)