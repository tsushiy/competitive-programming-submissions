n = int(input())
for i in range(n):
  t = input()
  nums = [[] for i in range(100)]
  num = ""
  nest = 0
  maxnest = 0
  for e in t:
    if e=="[":
      nest += 1
      maxnest = max(maxnest, nest)
    elif e!="[" and e!="]":
      num += e
    elif e=="]" and len(num):
      nums[nest].append(int(num)//2+1)
      num = ""
      nest -= 1
    else:
      nums[nest+1].sort()
      t = 0
      for i in range(len(nums[nest+1])//2+1):
        t += nums[nest+1][i]
      nums[nest+1] = []
      nums[nest].append(t)
      nest -= 1
  print(nums[1][0])