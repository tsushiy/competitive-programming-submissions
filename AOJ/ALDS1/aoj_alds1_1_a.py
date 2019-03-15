n = int(input())
a = list(map(int, input().split()))

def insertionSort():
  for i in range(1, n):
    v = a[i]
    j = i-1
    while j>=0 and a[j]>v:
      a[j+1] = a[j]
      j -= 1
    a[j+1] = v
    print(" ".join(map(str, a)))

print(" ".join(map(str, a)))
insertionSort()