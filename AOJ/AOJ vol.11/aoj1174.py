class UnionFind():

  def __init__(self, n):
    self.par = [i for i in range(n)]
    self.rank = [0] * n
    self.sizes = [1] * n

  def find(self, x):
    if self.par[x] != x:
      self.par[x] = self.find(self.par[x])
    return self.par[x]

  def union(self, x, y):
    x, y = self.find(x), self.find(y)
    if x == y:
      return False
    elif self.rank[x] < self.rank[y]:
      self.par[x] = y
      self.sizes[y] += self.sizes[x]
    elif self.rank[x] > self.rank[y]:
      self.par[y] = x
      self.sizes[x] += self.sizes[y]
    else:
      self.par[y] = x
      self.rank[x] += 1
      self.sizes[x] += self.sizes[y]
    return True

  def same(self, x, y):
    return self.find(x) == self.find(y)

  def size(self, x):
    return self.sizes[self.find(x)]

import sys
import copy
while True:
  h, w, c = [int(x) for x in sys.stdin.readline().split()]
  if h==0:
    break

  board = [[int(x) for x in sys.stdin.readline().split()] for i in range(h)]
  uf = UnionFind(h*w)
  ans = 0
  dx, dy = [1, 0, -1, 0], [0, 1, 0, -1]
  joined = {(0, 0)}

  for i in range(h):
    for j in range(w):
      for dxt, dyt in zip(dx, dy):
        if 0<=i+dyt<h and 0<=j+dxt<w and board[i][j]==board[i+dyt][j+dxt]:
          uf.union(w*i+j, w*(i+dyt)+j+dxt)
          joined.add((i+dyt, j+dxt))

  for c1 in range(1, 7):
    for c2 in range(1, 7):
      for c3 in range(1, 7):
        for c4 in range(1, 7):
          if c1==c2 or c2==c3 or c3==c4 or c4==c:
            continue
          uft = copy.deepcopy(uf)
          for ct in (c1, c2, c3, c4, c):
            for y, x in list(joined):
              if uft.same(w*y+x, 0):
                for dxt, dyt in zip(dx, dy):
                  if 0<=y+dyt<h and 0<=x+dxt<w and ct==board[y+dyt][x+dxt]:
                    uft.union(w*y+x, w*(y+dyt)+x+dxt)
                    joined.add((y+dyt, x+dxt))
          ans = max(ans, uft.size(0))
  print(ans)