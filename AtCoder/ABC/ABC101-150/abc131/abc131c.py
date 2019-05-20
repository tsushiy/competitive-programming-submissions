def gcd(a, b):
  return gcd(b, a%b) if b else a

def lcm(a, b):
  return a*b//gcd(a, b)

a, b, c, d = list(map(int, input().split()))
ttt = lcm(c, d)
tt = b-a+1
ta = b//c - (a-1)//c
tb = b//d - (a-1)//d
tc = b//ttt - (a-1)//ttt
print(tt-ta-tb+tc)