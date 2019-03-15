n = int(input())
a = list(map(int, input().split()))

def selectionSort():
  cnt = 0
  for i in range(n):
    minj = i
    for j in range(i, n):
      if a[j]<a[minj]:
        minj = j
    if i!=minj:
      a[i], a[minj] = a[minj], a[i]
      cnt += 1
  return cnt

cnt = selectionSort()
print(" ".join(map(str, a)))
print(cnt)