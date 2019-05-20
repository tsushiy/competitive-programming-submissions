n = int(input())

def dfs(x, f3, f5, f7):
  cnt = 0
  if x>n:
    return 0
  if f3>0 and f5>0 and f7>0:
    cnt += 1

  t1 = x*10+3
  t2 = x*10+5
  t3 = x*10+7
  cnt += dfs(t1, f3+1, f5, f7)
  cnt += dfs(t2, f3, f5+1, f7)
  cnt += dfs(t3, f3, f5, f7+1)
  return cnt

print(dfs(0, 0, 0, 0))