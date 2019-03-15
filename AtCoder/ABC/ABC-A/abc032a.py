a, b, n = [int(input()) for _ in range(3)]
while True:
  if n%a==0 and n%b==0:
    print(n)
    break
  else:
    n+=1