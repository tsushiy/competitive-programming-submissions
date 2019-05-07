s = input()
n = int(input())
for i in range(n):
  q = input().split()
  a, b = int(q[1]), int(q[2])
  if q[0]=="print":
    print(s[a:b+1])
  elif q[0]=="reverse":
    if a==0:
      s = s[b::-1]+s[b+1:]
    else:
      s = s[:a]+s[b:a-1:-1]+s[b+1:]
  elif q[0]=="replace":
    s = s[:a]+q[3]+s[b+1:]