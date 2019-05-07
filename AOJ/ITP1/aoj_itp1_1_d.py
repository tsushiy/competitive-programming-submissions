s = int(input())
h = s//3600
m = (s%3600)//60
s = s%60
print("{0}:{1}:{2}".format(h, m, s))