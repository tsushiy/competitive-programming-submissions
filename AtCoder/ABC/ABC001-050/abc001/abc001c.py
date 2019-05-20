deg, dis = list(map(int, input().split()))
deg /= 10
s = round(dis/60+0.0001, 1)
if s<=0.2:
  w = 0
elif s<=1.5:
  w = 1
elif s<=3.3:
  w = 2
elif s<=5.4:
  w = 3
elif s<=7.9:
  w = 4
elif s<=10.7:
  w = 5
elif s<=13.8:
  w = 6
elif s<=17.1:
  w = 7
elif s<=20.7:
  w = 8
elif s<=24.4:
  w = 9
elif s<=28.4:
  w = 10
elif s<=32.6:
  w = 11
else:
  w = 12

if w==0:
  dir = "C"
elif deg>=348.75 or deg<11.25:
  dir = "N"
elif deg<33.75:
  dir = "NNE"
elif deg<56.25:
  dir = "NE"
elif deg<78.75:
  dir = "ENE"
elif deg<101.25:
  dir = "E"
elif deg<123.75:
  dir = "ESE"
elif deg<146.25:
  dir = "SE"
elif deg<168.75:
  dir = "SSE"
elif deg<191.25:
  dir = "S"
elif deg<213.75:
  dir = "SSW"
elif deg<236.25:
  dir = "SW"
elif deg<258.75:
  dir = "WSW"
elif deg<281.25:
  dir = "W"
elif deg<303.75:
  dir = "WNW"
elif deg<326.25:
  dir = "NW"
else:
  dir = "NNW"

print(dir, w)