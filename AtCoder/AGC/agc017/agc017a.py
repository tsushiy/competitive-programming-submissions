n, p = list(map(int, input().split()))
a = list(map(int, input().split()))
flag = True
for ele in a:
  if ele%2==1:
    flag = False
if flag:
  if p==1:
    print(0)
  else:
    print(2**n)
else:
  print(2**(n-1))