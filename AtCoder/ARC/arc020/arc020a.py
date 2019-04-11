a, b = list(map(int, input().split()))
a, b = abs(a), abs(b)
if a==b:
  print("Draw")
elif a<b:
  print("Ant")
else:
  print("Bug")