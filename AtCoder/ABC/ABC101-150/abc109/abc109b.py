n = int(input())
s = set()
cur = ""
for i in range(n):
  w = input()
  if (cur!="" and cur!=w[0]) or w in s:
    print("No")
    exit()
  s.add(w)
  cur = w[-1]
print("Yes")