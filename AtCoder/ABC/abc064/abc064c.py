n = int(input())
a = list(map(int, input().split()))
d = {i:0 for i in range(9)}
for ele in a:
  if ele>=3200:
    d[8] += 1
  else:
    d[ele//400] = 1
ans1, ans2 = 0, 0
for k, v in d.items():
  if k!=8:
    ans1 += v
  ans2 += v
ans1 = max(1, ans1)
ans2 = ans2
print(ans1, ans2)