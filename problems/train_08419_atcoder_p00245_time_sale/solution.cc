#include<bits/stdc++.h>
using namespace std;
  
int w, h, n;
char mas[20][20];
  
typedef pair< int , int > Pi;
typedef pair< Pi , Pi > Piii;
Pi p;
  
struct sell{
  int d; //値引き額
  int s; //開始時刻
  int e; //終了時刻
};
sell shop[10];
  
int min_cost[20][20][1 << 10];
  
int bfs(){
  queue< Piii > que; // Pii( (買った商品, 今の時間), 座標)
  const int dy[] = { 1, 0, -1, 0}, dx[] = { 0, 1, 0, -1};
  
  memset( min_cost, -1, sizeof(min_cost));
  que.push( Piii( Pi( 0, 0), p));
  min_cost[p.second][p.first][0] = 0;
  
  int ret = 0;
  
  while(!que.empty()){
  
    Piii p = que.front(); que.pop();
  
    Pi point = p.second;
    int bit = p.first.first, time = p.first.second;
  
      
    if(ret < min_cost[point.second][point.first][bit]){
      ret = min_cost[point.second][point.first][bit];
    }
  
    for(int i = 0; i < 4; i++){
      int ny = point.second + dy[i], nx = point.first + dx[i];
      if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
  
      if(isdigit(mas[ny][nx])){
          
        int time_sell = mas[ny][nx] - '0';
  
        if(!((bit >> time_sell) & 1)){
            
          sell se = shop[time_sell];
  
          if(se.s > time){ //待ってプッシュ
            que.push( Piii( Pi( bit, se.s), point));
          } else if(se.s <= time && time < se.e){ //時間内だったら買ってみる
            int next_bit = bit | (1 << time_sell);
            if(min_cost[point.second][point.first][bit] + se.d > min_cost[point.second][point.first][next_bit]){
              que.push( Piii( Pi( next_bit, time), point));
              min_cost[point.second][point.first][next_bit] = min_cost[point.second][point.first][bit] + se.d;
            }
          }
        }
  
      } else {
        if(min_cost[point.second][point.first][bit] > min_cost[ny][nx][bit]){
          que.push( Piii( Pi( bit, time + 1), Pi( nx, ny)));
          min_cost[ny][nx][bit] = min_cost[point.second][point.first][bit];
        }
      }
    }
  }
  return ret;
}
  
int main(){
  while(cin >> w >> h, w){
    for(int i = 0; i < h; i++){
      for(int j = 0; j < w; j++){
        cin >> mas[i][j];
        if(mas[i][j] == 'P') p = Pi( j, i);
      }
    }
    cin >> n;
  
    for(int i= 0; i < n; i++){
      int g;
      cin >> g;
      cin  >> shop[g].d >> shop[g].s >> shop[g].e;
    }
  
    cout << bfs() << endl;
  }
}