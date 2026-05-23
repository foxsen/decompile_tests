#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cout<<*i<<" "; cout<<endl; }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;
int a[10][10];
int w, h;
int sx, sy;
int N;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int tmp1[10], tmp2[10];
int dfs(int x, int y, int n){
  if(n == N){
    //REP(i, n) printf("(%d %d) ", tmp1[i], tmp2[i]);
    //cout<<endl;
    if(x == sx || y == sy) return 1;
    else return 0;
  }
  int res = 0;
  REP(r, 4){
    int nx = x + dx[r];
    int ny = y + dy[r];
    while(nx >= 0 && nx < w && ny >= 0 && ny < h){
      if(a[ny][nx] == 1){
        break;
      }
      ny += dy[r];
      nx += dx[r];
    }
    if(nx >= 0 && nx < w && ny >= 0 && ny < h){
      assert(a[ny][nx] == 1);
      a[ny][nx] = 0;
      //tmp1[n] = nx, tmp2[n] = ny;
      res += dfs(nx, ny, n + 1);
      a[ny][nx] = 1;
    }
  }
  return res;
}


int main(){
  while(cin>>w>>h && w){
    N = 0;
    REP(y, h) REP(x, w){
      cin>>a[y][x];
      if(a[y][x] == 2){
        a[y][x] = 0;
        sx = x, sy = y;
      }
      if(a[y][x] == 1) N ++;
    }
    cout<<dfs(sx, sy, 0)<<endl;
  }
  return 0;
}