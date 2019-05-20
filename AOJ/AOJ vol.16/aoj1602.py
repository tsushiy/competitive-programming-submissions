while True:
  n = int(input())
  if n==0:
    break
  if n==1:
    print(int(input()))
    continue

  op = "+*"
  f = [input() for i in range(n)]
  f = f[::-1]
  stack = []

  for i in range(n):
    if f[i][-1] not in op:
      stack.append(f[i])
    else:
      nest = f[i].count(".")
      if f[i][-1]=="*":
        cur = 1
        while len(stack):
          if stack[-1].count(".")!=nest+1:
            break
          else:
            t = stack.pop().strip(".")
            cur *= int(t)
        stack.append("."*(nest)+str(cur))
      else:
        cur = 0
        while len(stack):
          if stack[-1].count(".")!=nest+1:
            break
          else:
            t = stack.pop().strip(".")
            cur += int(t)
        stack.append("."*(nest)+str(cur))
  print(stack[0])