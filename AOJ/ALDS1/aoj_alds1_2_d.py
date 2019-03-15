n = int(input())
a = [int(input()) for i in range(n)]
cnt = 0

def insertionSort(g):
  global cnt
  for i in range(1, n):
    v = a[i]
    j = i-g
    while j>=0 and a[j]>v:
      a[j+g] = a[j]
      j -= g
      cnt += 1
    a[j+g] = v

def shellSort():
  m = len(a)//2
  g = [m]
  while m>1:
    m = m//2
    g.append(m)
  print(len(g))
  print(" ".join(map(str, g)))
  for ele in g:
    insertionSort(ele)

shellSort()
print(cnt)
for ele in a:
  print(ele)