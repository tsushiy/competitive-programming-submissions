#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define rep(i,e) for(int i=0;i<(e);++i)

int w, h, lx, ly, rx, ry, nlx, nly, nrx, nry;
int t, lsx, lsy, rsx, rsy;
char l[50][50], r[50][50];
int drx[4]={0,1,0,-1}, dy[4]={1,0,-1,0}, dlx[4]={0,-1,0,1};

int main() {
  while(true){
    cin>>w>>h;
    if(w==0)break;

    bool visited[50][50][50][50]={};
    bool ans = false;
    int t, lsx, lsy, rsx, rsy;

    rep(i,h){
      rep(j,w){
        cin>>l[i][j];
        if(l[i][j]=='L') lsx=j, lsy=i;
      }
      rep(j,w){
        cin>>r[i][j];
        if(r[i][j]=='R') rsx=j, rsy=i;
      }
    }
    //cout<<lsx<<" "<<lsy<<" "<<rsx<<" "<<rsy<<endl;

    queue<tuple<int, int, int, int>> q;
    q.push(make_tuple(lsx, lsy, rsx, rsy));
    visited[lsx][lsy][rsx][rsy] = true;
    while(q.size()){
      tie(lx, ly, rx, ry) = q.front(); q.pop();
      //cout<<lx<<" "<<ly<<" "<<rx<<" "<<ry<<endl;

      rep(i,4){
        nlx = lx+dlx[i], nly = ly+dy[i];
        nrx = rx+drx[i], nry = ry+dy[i];
        if(nlx<0 or nlx>=w) nlx = lx;
        if(nrx<0 or nrx>=w) nrx = rx;
        if(nly<0 or nly>=h) nly = ly;
        if(nry<0 or nry>=h) nry = ry;
        if(l[nly][nlx]=='\%' and r[nry][nrx]=='\%'){
          ans = true; break;
        }
        else if(l[nly][nlx]=='\%' or r[nry][nrx]=='\%') continue;
        else if(l[nly][nlx]=='#' and r[nry][nrx]=='#') continue;
        else if(l[nly][nlx]=='#'){
          nly = ly, nlx = lx;
        }
        else if(r[nry][nrx]=='#'){
          nry = ry, nrx = rx;
        }
        if(visited[nlx][nly][nrx][nry]==false){
          q.push(make_tuple(nlx, nly, nrx, nry));
          visited[nlx][nly][nrx][nry] = true;
        }
      }
    }
    if (ans) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
  return 0;
}