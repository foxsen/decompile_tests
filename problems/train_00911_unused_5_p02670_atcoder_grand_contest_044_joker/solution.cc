#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  vector<vector<int>> dist(N,vector<int>(N));
  for(int i = 0; i < N; ++i)
    for(int j = 0; j < N; ++j)
      dist[i][j] = min({i,N-1-i,j,N-1-j});

  int ans = 0;
  vector<vector<bool>> exist(N,vector<bool>(N,true));
  for(int i = 0; i < N*N; ++i){
    int p;
    cin >> p;
    --p;
    int h = p/N, w = p%N;
    ans += dist[h][w];
    // cerr << h << " " << w << " " << dist[h][w] << endl;
    exist[h][w] = false;
    queue<pair<int,int>> Q;
    Q.emplace(h,w);
    int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
    while(Q.size()){
      auto [x, y] = Q.front();
      Q.pop();
      int d = dist[x][y] + exist[x][y];
      for(int i = 0; i < 4; ++i){
        int x_ = x + dx[i], y_ = y + dy[i];
        if(x_ >= 0 and x_ < N and y_ >= 0 and y_ < N and dist[x_][y_] > d){
          dist[x_][y_] = d;
          Q.emplace(x_,y_);
        }
      }
    }
  }
  cout << ans << endl;
}
