n = int(input())
a = list(map(int, input().split()))
b = [(i+1, ele) for i, ele in enumerate(a)]

b.sort(key=(lambda x:x[1]), reverse=True)
for ele in b:
  print(ele[0])