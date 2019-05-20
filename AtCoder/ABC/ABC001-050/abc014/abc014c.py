n = int(input())
MAX = 10**6+5
s = [0]*(MAX)
for i in range(n):
  a, b = list(map(int, input().split()))
  s[a] += 1
  s[b+1] -= 1
acc = [0]*MAX
acc[0] = s[0]
for i in range(1, MAX):
  acc[i] = acc[i-1]+s[i]
print(max(acc))