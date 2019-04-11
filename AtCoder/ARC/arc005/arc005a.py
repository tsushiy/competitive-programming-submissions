n = int(input())
w = input().split()
w[-1] = w[-1][:-1]
ans = 0
for ele in w:
  if ele=="TAKAHASHIKUN" or ele=="Takahashikun" or ele=="takahashikun":
    ans += 1
print(ans)