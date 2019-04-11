n = int(input())
s = [input() for _ in range(n)]
m = int(input())
t = [input() for _ in range(m)]
ans = 0

for ele in s:
  ans = max(ans, s.count(ele)-t.count(ele))
print(ans)