n = int(input())
i = 1
while i<=n:
  if i%3==0:
    print("", i, end="")
  else:
    x = i
    while x:
      if x%10==3:
        print("", i, end="")
        break
      x //= 10
  i += 1
print()