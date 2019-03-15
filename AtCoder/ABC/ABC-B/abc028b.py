a = "ABCDEF"
d = dict()
for ele in a:
  d[ele] = 0
s = input()
for ele in s:
  d[ele] += 1
ans = []
for ele in a:
  ans.append(str(d[ele]))
print(" ".join(ans))