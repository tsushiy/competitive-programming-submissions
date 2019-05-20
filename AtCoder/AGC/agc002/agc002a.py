a, b = list(map(int, input().split()))
if a>0 and b>0:
  print("Positive")
elif a<=0<=b:
  print("Zero")
else:
  if (b-a)%2:
    print("Positive")
  else:
    print("Negative")