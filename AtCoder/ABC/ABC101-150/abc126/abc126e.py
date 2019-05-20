class UnionFind():

  def __init__(self, n):
    self.par = [i for i in range(n)]
    self.rank = [0] * n

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
    elif self.rank[x] > self.rank[y]:
      self.par[y] = x
    else:
      self.par[y] = x
      self.rank[x] += 1
    return True

  def same(self, x, y):
    return self.find(x) == self.find(y)

n, m = list(map(int, input().split()))
uf = UnionFind(n+1)
ans = 0
for i in range(m):
  x, y, z = list(map(int, input().split()))
  ans += uf.union(x, y)
print(n-ans)