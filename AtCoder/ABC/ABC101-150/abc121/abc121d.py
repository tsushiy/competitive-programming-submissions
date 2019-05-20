a, b = list(map(int, input().split()))

def acc_xor(x):
  if x%4==0:
    return x
  elif x%4==1:
    return 1
  elif x%4==2:
    return x+1
  else:
    return 0

print(acc_xor(a-1)^acc_xor(b))