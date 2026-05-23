#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

#define rep(i,j) REP((i), 0, (j))
#define REP(i,j,k) for(int i=(j);(i)<(k);++i)
#define BW(a,x,b) ((a)<=(x)&&(x)<=(b))
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define INF 1 << 30
#define EPS 1e-10

typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef vector<int> vi;
typedef queue<int> qi;
typedef long long ll;

int H, W, t[20][20];
int dy[] = {0, 1}, dx[] = {1,0}; // 横　縦

int judge(int y, int x){
  map<int, int>m;
  for(int i = -1; i < 1; i++){
    for(int j = -1; j < 1; j++){
      int ny = y+i, nx = x+j;
      if(ny < 0 || nx < 0 || t[ny][nx] == -1 || m.count(t[ny][nx])) continue;
      m[t[ny][nx]] = 1;
    }
  }
  if(m.size() < 4) return 1;
  return 0;
}

int dfs(int n){
  int i, j, res = 0;
  for(i = 0; i < H; i++) for(j = 0; j < W; j++) if(t[i][j] == -1) goto b;
 b:

  if(i == H && j == W) return 1;

  int tmp[20][20];
  rep(i, H) rep(j, W) tmp[i][j] = t[i][j];

  t[i][j] = n;
  rep(d, 2){
    int x = j+dx[d], y = i+dy[d];
    if(x < 0 || x >= W || y < 0 || y >= H || t[y][x] != -1) continue;
    t[y][x] = n;
    if(judge(i, j)) res += dfs(n+1);
    t[y][x] = -1;
  }
  rep(i, H) rep(j, W) t[i][j] = tmp[i][j];

  return res;
}

int main(){
  while(scanf("%d%d", &H, &W) && H+W){
    memset(t, -1, sizeof(t));
    printf("%d\n", dfs(0));
  }
  return 0;
}