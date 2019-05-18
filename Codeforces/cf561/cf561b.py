k = int(input())
s = ""
for i in range(5, 10**4+1):
  t = k/i
  if t.is_integer() and t>=5:
    for j in range(i):
      n = int(j%5)
      ss = ("aeiou"[n:5]+"aeiou"[:n])*((int(t)+5)//5)
      s += ss[:int(t)]
    print(s)
    exit()
print(-1)