n = int(input())
a = list(map(int, input().split()))
a = sorted(set(a))
print(" ".join(map(str, a)))