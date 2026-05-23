#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

char c[14][14];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int belong[14][14];
int ok[10000];
int gx,gy;

int ans = 0;
int ccc = 0;
void dfs(int x,int y,int C,int px,int py){
  if( c[y][x] == '#' || c[y][x] == '*') return;
  if( C + abs(x-gx) + abs(y-gy) >= ans ) return;
  if( c[y][x] == 'G'){
    ans = C;
    return;
  }
  for(int i = 0 ; i < 4 ; i++){
    int tx = x + dx[i];
    int ty = y + dy[i];
    if( px == tx && ty == py ) continue;
    if( c[ty][tx] == '*' ) return;
  }
  char cur = c[y][x];
  c[y][x] = '*';
  for(int i = 0 ; i < 4 ; i++){
    int tx = x + dx[i];
    int ty = y + dy[i];
    if( c[ty][tx] == 'X' ){
      int b = belong[ty][tx];
      if( ok[b] > 0 ){
	ok[b]--;
	dfs(tx,ty,C+1,x,y);
	ok[b]++;
      }
    }else{
      dfs(tx,ty,C+1,x,y);
    }
  }
  c[y][x] = cur;
  return;
}
void grouping(int x,int y,int k){
  if( c[y][x] != 'X') return;
  if( belong[y][x] != -1 ) return;
  belong[y][x] = k;
  ccc++;
  for(int i = 0 ; i < 4 ; i++)
    grouping(x+dx[i],y+dy[i],k);
}

int main(){
  ios_base::sync_with_stdio(false);
  int W,H;
  while(cin >> W >> H && W){
    rep(i,14)rep(j,14) belong[i][j] = -1;
    rep(i,14)rep(j,14) 
      c[i][j] = '#';
    int sx , sy;
    for(int i = 0 ; i < H ; i++){
      for(int j = 0 ; j < W ; j++){
	cin >> c[i+1][j+1];
	if(c[i+1][j+1] == 'S'){
	  c[i+1][j+1] = '.';
	  sx = j+1 , sy = i+1;
	}else if(c[i+1][j+1] == 'G' ){
	  gx = j+1 , gy = i+1;
	}
      }
    }
    int k = 0;
    for(int i = 1 ; i <= H ; i++){
      for(int j = 1 ; j <= W ; j++){
	if( c[i][j] == 'X' && belong[i][j] == -1){
	  ccc = 0;
	  grouping(j,i,k);
	    ok[k] = ccc / 2;
	    k++;
	}
      }
    }
    ans = 1e7;
    dfs(sx,sy,0,-1,-1);
    cout << ans << endl;
    
  }
}