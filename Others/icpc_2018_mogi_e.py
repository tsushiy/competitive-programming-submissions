from collections import defaultdict

while True:
  n, m = map(int, input().split())
  if n==0 and m==0:
    break
  else:
    graph = defaultdict(set)
    for _ in range(m):
      u, v = map(int, input().split())
      graph[u-1].add(v-1)
      graph[v-1].add(u-1)
    
    # 2部グラフ判定
    color = [0]*n
    def dfs(v, c):
      color[v] = c
      for i in graph[v]:
        if color[i] == c:
          return False
        if color[i] == 0 and dfs(i, -c) == False:
          return False
      return True

    flag = dfs(0, 1)
    cnt = color.count(1)
    if flag == False:
      print(0)
    else:
      ansset = set()
      if cnt%2 == 0:
        ansset.add(cnt//2)
      if (n-cnt)%2 == 0:
        ansset.add((n-cnt)//2)
      ansset = sorted(ansset)
      if len(ansset) > 0:
        print(len(ansset))
        for ele in ansset:
          print(ele)
      else:
        print(0)