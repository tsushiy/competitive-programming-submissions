q = int(input())
for i in range(q):
  n =  str(int(input()))
  nums = set()

  count = 0
  flag = 0
  while not n in nums:
    nums.add(n)
    max_ = -1
    if len(n) == 1:
      flag = 1
      break
    for i in range(1,len(n)):
      a = int(n[:i])
      b = int(n[i:])
      if max_ < a*b:
        max_ = a*b
    n = str(max_)
    count += 1

  if flag == 1:
    print(count)
  else:
    print(-1)