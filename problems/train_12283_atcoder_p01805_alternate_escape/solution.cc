#include <bits/stdc++.h>

#define REP(i,n) for(int i=0;i<(int)n;++i)

using namespace std;
template<typename T>
using table = vector<vector<T>>;
using wall = bitset<4>;

int main() {
  while(1){
    int h,w,r,c;
    cin>>h>>w>>r>>c;
    if(!h)break;
    int H=h+2, W=w+2;
    table<wall> g(H,vector<wall>(W));
    REP(i,h+1) {
      REP(j,w) {
        bool b;
        cin>>b;
        g[i][j+1][1] = g[i+1][j+1][3] = b;
      }
      if (i < h) {
        REP(j, w+1) {
          bool b;
          cin>>b;
          g[i+1][j][0] = g[i+1][j+1][2] = b;
        }
      }
    }
    table<bool> win(H, vector<bool>(W, false));
    REP(i,W) win[0][i] = win[h+1][i] = true;
    REP(i,H) win[i][0] = win[i][w+1] = true;
    using P = pair<int, int>;
    queue<P> que;
    REP(i,w) {
      que.emplace(1,i+1);
      que.emplace(h,i+1);
    }
    REP(i,h) {
      que.emplace(i+1,1);
      que.emplace(i+1,w);
    }
    int di[] = {0, 1, 0, -1};
    int dj[] = {1, 0, -1, 0};
    while(!que.empty()) {
      int i,j;
      tie(i,j) = que.front(); que.pop();
      bool ok_t = false, ok_f = false;
      REP(k,4) {
        if(win[i+di[k]][j+dj[k]]) {
          if (g[i][j][k]) ok_t = true;
          else ok_f = true;
        }
      }
      if (ok_t && ok_f) {
        win[i][j] = true;
        REP(k,4) {
          int ni=i+di[k];
          int nj=j+dj[k];
          if (win[ni][nj]) continue;
          que.emplace(ni,nj);
        }
      }
    }
    bool isw = false;
    REP(k,4) {
      if (!g[r][c][k] && win[r+di[k]][c+dj[k]]) isw = true;
    }
    if (isw) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}