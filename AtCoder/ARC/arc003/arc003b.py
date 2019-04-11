n = int(input())
s = [input()[::-1] for i in range(n)]
s.sort()
for ele in s:
  print(ele[::-1])