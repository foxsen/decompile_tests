#include<bits/stdc++.h>
using namespace std;
using P = pair<int,int>;
int INF = 1e9;
 
int main(){
  int H, W, K;
  cin >> H >> W >> K;
  
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  
  vector<vector<int>> dist(H+2,vector<int>(W+2,INF));
  vector<vector<char>> vec(H+2,vector<char>(W+2,'@'));
  for(int i=1; i<=H; i++){
    for(int j=1; j<=W; j++){
      cin >> vec[i][j];
    }
  }
  
  vector<int> dx = {0,1,0,-1};
  vector<int> dy = {1,0,-1,0};
  P start = {x1,y1};
  queue<P> Q;
  Q.push(start);
  dist[x1][y1] = 0;
  while(Q.size()){
    P p = Q.front();
    Q.pop();
    int nx = p.first;
    int ny = p.second;
    for(int i=0; i<4; i++){
      for(int j=1; j<=K; j++){
        if(vec[nx + dx[i]*j][ny + dy[i]*j] == '@'){
          break;
        }
        else if(dist[nx + dx[i]*j][ny + dy[i]*j] <= dist[nx][ny]){
          break;
        }
        else if(dist[nx + dx[i]*j][ny + dy[i]*j] > dist[nx][ny] + 1){
          dist[nx + dx[i]*j][ny + dy[i]*j] = dist[nx][ny] + 1;
          P q = {nx + dx[i]*j, ny + dy[i]*j};
          Q.push(q);
        }
      }
    }
  }
  if(dist[x2][y2] == INF){
    dist[x2][y2] = -1;
  }
  cout << dist[x2][y2] << endl;
}