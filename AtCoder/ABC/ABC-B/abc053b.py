s = input()
l = s.index("A")
r = s[::-1].index("Z")
print(len(s)-r-l)