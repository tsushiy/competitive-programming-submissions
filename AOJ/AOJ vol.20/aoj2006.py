n = int(input())
abc = [".,!? ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
for i in range(n):
  s = input()
  ans = ""
  cur = -1
  num = -1
  for e in s:
    e = int(e)
    if cur ==-1 and e==0:
      continue
    elif e==0:
      t = len(abc[cur-1])
      ans += abc[cur-1][num%t]
      num = -1
      cur = -1
    else:
      cur = e
      num += 1
  print(ans)