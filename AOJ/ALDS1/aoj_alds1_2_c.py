n = int(input())
c = list(input().split())
c1, c2 = c[:], c[:]

def bubbleSort():
  for i in range(n):
    for j in range(n-1, i, -1):
      if c1[j][-1]<c1[j-1][-1]:
        c1[j], c1[j-1] = c1[j-1], c1[j]

def selectionSort():
  for i in range(n):
    minj = i
    for j in range(i, n):
      if c2[j][-1]<c2[minj][-1]:
        minj = j
    c2[i], c2[minj] = c2[minj], c2[i]

bubbleSort()
selectionSort()
print(" ".join(map(str, c1)))
print("Stable")
print(" ".join(map(str, c2)))
if c1==c2:
  print("Stable")
else:
  print("Not stable")