#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define IINF (INT_MAX)
#define LEN (1<<8)

using namespace std;

int G[7][5],dp[7][LEN];
int tmp_G[7][5];

inline int getCost(int x){ return ((x==3)?80:((x==2)?70:((x==1)?60:0))); }

inline bool isValid(int x,int y){ return ( 0 <= x && x < 5 && 1 <= y && y < 6); }

inline void push(int x,int y,int cnt){
  if( isValid(x  ,y  ) ) ( tmp_G[y  ][x  ]+=cnt ) %= 4;
  if( isValid(x+1,y  ) ) ( tmp_G[y  ][x+1]+=cnt ) %= 4;
  if( isValid(x  ,y+1) ) ( tmp_G[y+1][x  ]+=cnt ) %= 4;
  if( isValid(x+1,y+1) ) ( tmp_G[y+1][x+1]+=cnt ) %= 4;
}

inline void automatically_pusher(int tmp,int y){
  if( !( 1 <= y && y <= 4 ) ) return;
  int x = 0;
  while( x < 4 ){
    int cnt = tmp & ((1<<2)-1);
    tmp >>= 2;
    push(x,y,cnt);
    x++;
  }
}

int main(){
  cin.tie(0);
  std::ios::sync_with_stdio(0);
  int T;
  cin >> T;
  while(T--){
    rep(i,7)rep(j,5)G[i][j] = -1;
    REP(i,1,6)rep(j,5){
      cin >> G[i][j];
      G[i][j]--;
    }
    int answer = 0;
    rep(i,7)rep(k,LEN)dp[i][k] = -1;
    dp[0][0] = 0;
    REP(i,1,6)rep(pre,LEN)if(dp[i-1][pre]!=-1)rep(cur,LEN){
	rep(j,7)rep(k,5)tmp_G[j][k] = G[j][k];
	automatically_pusher(pre,i-1);
	automatically_pusher(cur,i);
	int cost = 0;
	rep(j,5)if(G[i][j]!=-1)cost+=getCost(tmp_G[i][j]);
	dp[i][cur] = max(dp[i][cur],dp[i-1][pre]+cost);
	answer = max(answer,dp[i][cur]);
      }
    cout << answer << endl;
  }
  return 0;
}