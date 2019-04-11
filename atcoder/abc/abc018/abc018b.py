s = input()
n = int(input())
for i in range(n):
  l, r = list(map(int, input().split()))
  if l-2==-1:
    s = s[:l-1]+s[r-1::-1]+s[r:]
  else:
    s = s[:l-1]+s[r-1:l-2:-1]+s[r:]
print(s)