n, m = list(map(int, input().split()))
e = [[] for _ in range(n+1)]
for i in range(m):
  a, b = list(map(int, input().split()))
  e[a].append(b)
  e[b].append(a)
for i in range(1, n+1):
  print(len(e[i]))