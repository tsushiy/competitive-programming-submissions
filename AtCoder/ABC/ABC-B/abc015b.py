n = int(input())
a = list(map(int, input().split()))
b = [ele for ele in a if ele>0]
from math import ceil
print(ceil(sum(b)/len(b)))