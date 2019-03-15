n = int(input())
a = list(map(int, input().split()))

def bubbleSort():
  cnt = 0
  flag = 1
  while flag:
    flag = 0
    for j in range(n-1, 0, -1):
      if a[j]<a[j-1]:
        a[j], a[j-1] = a[j-1], a[j]
        flag = 1
        cnt += 1
  return cnt

cnt = bubbleSort()
print(" ".join(map(str, a)))
print(cnt)