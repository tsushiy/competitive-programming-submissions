n = int(input())
if n==1:
  print("Not Prime")
elif n in (2, 3, 5):
  print("Prime")
elif n%2==0 or n%3==0 or n%5==0:
  print("Not Prime")
else:
  print("Prime")