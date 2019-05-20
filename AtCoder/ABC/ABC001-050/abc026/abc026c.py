n = int(input())

sub = [[] for i in range(n)]
salary = [0 for i in range(n)]

for i in range(n-1):
  b = int(input())
  b -= 1
  sub[b].append(i+1)

for i in range(n):
  if len(sub[i])==0:
    salary[i] = 1

while not all(salary):
  for i in range(n):
    if salary[i]>0:
      continue
    flag = True
    for j in sub[i]:
      if salary[j]==0:
        flag = False
        break
    if flag:
      t = [salary[j] for j in sub[i]]
      if len(t)==1:
        salary[i] = t[0]*2+1
      else:
        salary[i] = max(t)+min(t)+1
print(salary[0])