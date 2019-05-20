n = int(input())
graph = [[0 for i in range(n)] for i in range(n)]
for i in range(n):
  graph[i] = list(map(int, input().split()))
ans = 0
for i in range(n):
  for j in range(i+1, n):
    ans += min(graph[i][j], graph[j][i])
print(ans)