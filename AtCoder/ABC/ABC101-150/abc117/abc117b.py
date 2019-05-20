n = int(input())
l = list(map(int, input().split()))
l.sort()
if sum(l[:-1])>l[-1]:
  print("Yes")
else:
  print("No")