s = input().split()
q = []
for ele in s:
  if ele in "+-*":
    b = q.pop()
    a = q.pop()
    q.append(str(eval(a+ele+b)))
  else:
    q.append(ele)
print(q[0])