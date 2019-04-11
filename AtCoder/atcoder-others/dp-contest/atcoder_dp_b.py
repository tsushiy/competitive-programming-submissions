import sys
sys.setrecursionlimit(10000)

a, b = map(int, input().split())
al = list(map(int, input().split()))
bl = list(map(int, input().split()))
dp = [[-1]*(b+1) for _ in range(a+1)]
dp[a][b] = 0

def rec(l, r, turn):
  if dp[l][r] != -1:
    return dp[l][r]
  
  if turn==1:
    res = float("INF")
    if l<a:
      res = min(res, rec(l+1, r, 0))
    if r<b:
      res = min(res, rec(l, r+1, 0))
  else:
    res = float("-INF")
    if l<a:
      res = max(res, rec(l+1, r, 1)+al[l])
    if r<b:
      res = max(res, rec(l, r+1, 1)+bl[r])
  dp[l][r] = res
  return res

print(rec(0,0,0))