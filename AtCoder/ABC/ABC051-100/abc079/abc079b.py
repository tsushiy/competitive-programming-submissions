n = int(input())
lucas = [0]*90
lucas[0], lucas[1] = 2, 1
for i in range(2, 90):
  lucas[i] = lucas[i-1]+lucas[i-2]
print(lucas[n])