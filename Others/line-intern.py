def main(argv):
  s, g, st = argv[0], argv[1], argv[2]
  print(s, g, st)

  area1 = ["A1", "A2", "A3", "A4", "A5", "A6", "A7"]
  area2 = ["A7", "A8", "A9", "A10", "A11", "A12", "A13"]
  area3 = ["B1", "B2", "B3", "B4", "B5", "A7"]

  d_area1 = [3, 5, 2, 3, 4, 3]
  d_area1rev = d_area1[::-1]
  d_area2 = [4, 2, 2, 3, 6, 2]
  d_area2rev = d_area2[::-1]
  d_area3 = [4, 3, 3, 2, 3]
  d_area3rev = d_area3[::-1]

  tt_area1_up = [[i for i in range(355+sum(d_area1[:j]), 1376+sum(d_area1[:j]), 5)] for j in range(7)]
  tt_area2_up = [[i for i in range(380+sum(d_area2[:j]), 1391+sum(d_area2[:j]), 10)] for j in range(7)]
  for i in range(7):
    tt_area2_up[i].append(370+sum(d_area2[:i]))
  tt_area3_up = [[i for i in range(360+sum(d_area3[:j]), 1375+sum(d_area3[:j]), 6)] for j in range(6)]
  tt_area1_down = [[i for i in range(371+sum(d_area1rev[:j]), 1382+sum(d_area1rev[:j]), 10)] for j in range(7)]
  for j in range(7):
    tt_area1_down.extend([i for i in range(366+sum(d_area1rev[:j]), 1377+sum(d_area1rev[:j]), 10)])
  tt_area2_down = [[i for i in range(352+sum(d_area2rev[:j]), 1373+sum(d_area2rev[:j]), 10)] for j in range(7)]
  tt_area3_down = [[i for i in range(371+sum(d_area3rev[:j]), 1380+sum(d_area3rev[:j]), 6)] for j in range(6)]

  hh, mm = map(int, st.split(":"))
  st = 60*hh+mm

  def calc_time(station_s, station_g, start_time):
    first_time = 0
    second_time = 9999
    arrivaltime_first = 0
    arrivaltime_second = 9999
    if station_s in area1 and station_g in area1:
      sn = int(s[1:])-1
      gn = int(g[1:])-1
      if sn<gn:
        tt_area1_up[sn].sort()
        for idx, time in enumerate(tt_area1_up[sn]):
          if start_time <= time:
            first_time = time
            if idx <len(tt_area1_up)-1:
              second_time = tt_area1_up[sn][idx+1]
            break
        arrivaltime_first = first_time + sum(d_area1[sn:gn+1])
        if second_time != 9999:
          arrivaltime_second = second_time + sum(d_area1[sn:gn+1])
      elif sn>gn:
        tt_area1_down[sn].sort()
        for idx, time in enumerate(tt_area1_down[sn]):
          if start_time <= time:
            first_time = time
            if idx <len(tt_area1_down)-1:
              second_time = tt_area1_down[sn][idx+1]
            break
        arrivaltime_first = first_time + sum(d_area1[gn:sn+1])
        if second_time != 9999:
          arrivaltime_second = second_time + sum(d_area1[gn:sn+1])
    
    elif station_s in area2 and station_g in area2:
      sn = int(s[1:])-1
      gn = int(g[1:])-1
      if sn<gn:
        tt_area2_up[sn].sort()
        for idx, time in enumerate(tt_area2_up[sn]):
          if start_time <= time:
            first_time = time
            if idx <len(tt_area2_up)-1:
              second_time = tt_area2_up[sn][idx+1]
            break
        arrivaltime_first = first_time + sum(d_area2[sn:gn+1])
        if second_time != 9999:
          arrivaltime_second = second_time + sum(d_area2[sn:gn+1])
      elif sn>gn:
        tt_area2_down[sn].sort()
        for idx, time in enumerate(tt_area2_down[sn]):
          if start_time <= time:
            first_time = time
            if idx <len(tt_area2_down)-1:
              second_time = tt_area2_down[sn][idx+1]
            break
        arrivaltime_first = first_time + sum(d_area2[gn:sn+1])
        if second_time != 9999:
          arrivaltime_second = second_time + sum(d_area2[gn:sn+1])
    
    elif station_s in area3 and station_g in area3:
      sn = int(s[1:])-1
      gn = int(g[1:])-1
      if sn<gn:
        tt_area3_up[sn].sort()
        for idx, time in enumerate(tt_area3_up[sn]):
          if start_time <= time:
            first_time = time
            if idx <len(tt_area3_up)-1:
              second_time = tt_area3_up[sn][idx+1]
            break
        arrivaltime_first = first_time + sum(d_area3[sn:gn+1])
        if second_time != 9999:
          arrivaltime_second = second_time + sum(d_area3[sn:gn+1])
      elif sn>gn:
        tt_area2_down[sn].sort()
        for idx, time in enumerate(tt_area2_down[sn]):
          if start_time <= time:
            first_time = time
            if idx <len(tt_area2_down)-1:
              second_time = tt_area2_down[sn][idx+1]
            break
        arrivaltime_first = first_time + sum(d_area3[gn:sn+1])
        if second_time != 9999:
          arrivaltime_second = second_time + sum(d_area3[gn:sn+1])

    elif station_s in area1 and station_g in area2:
      aft3, ast3 = 9999, 9999
      ft1, st1, aft1, ast1 = calc_time(station_s, "A7", start_time)
      ft2, st2, aft2, ast2 = calc_time("A7", station_g, aft1)
      if aft2 != 9999:
        ft3, st3, aft3, ast3 = calc_time("A7", station_g, ast1)
      
      at_list = [[aft2, -ft1, aft1, ft2], [ast2, -ft1, ast1, st2], [aft3, -st1, aft1, ft3], [ast3, -st1, ast1, st3]]
      at_list.sort()
      at2, ft1, at1, ft2 = at_list[0]
      print("A "+s+" "+str(-ft1)+" - A7 "+ str(at1))
      print("B "+"A7 "+str(-ft2)+" - "+g+" "+ str(at2))
      exit()


      


    return first_time, second_time, arrivaltime_first, arrivaltime_second
    
  a, b, c, d = calc_time(s, g, st)
  print(s[0]+" "+str(a//60)+":"+str(a%60)+" - "+g+" "+ str(c//60)+":"+str(c%60))

if __name__ == "__main__":
  arglist = list(input().split())
  main(arglist)