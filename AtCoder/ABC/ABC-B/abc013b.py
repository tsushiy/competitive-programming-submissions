a = int(input())
b = int(input())
print(min(abs(a-b), min(abs(a-10), a)+min(abs(b-10), b)))