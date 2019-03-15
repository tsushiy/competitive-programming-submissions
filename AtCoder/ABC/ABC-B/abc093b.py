a, b, k = map(int, input().split())
ans = set()
for i in range(a, min(a+k, b+1)):
  ans.add(i)
for i in range(b, max(b-k, a+k-1), -1):
  ans.add(i)
for ele in sorted(ans):
  print(ele)