n, a, b, c = list(map(int, input().split()))
l = [int(input()) for i in range(n)]

def dfs(cur, ta, tb, tc):
  if cur==n:
    if ta<=0 or tb<=0 or tc<=0:
      return 1e9
    else:
      return abs(a-ta)+abs(b-tb)+abs(c-tc)-30

  t1 = dfs(cur+1, ta, tb, tc)
  t2 = dfs(cur+1, ta+l[cur], tb, tc)+10
  t3 = dfs(cur+1, ta, tb+l[cur], tc)+10
  t4 = dfs(cur+1, ta, tb, tc+l[cur])+10
  return min(t1, t2, t3, t4)

print(dfs(0, 0, 0, 0))