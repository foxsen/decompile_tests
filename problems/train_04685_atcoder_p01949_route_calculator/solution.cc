#include<bits/stdc++.h>
#define int long long
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef pair<int,int>P;
typedef pair<P,int>P2;
vector<P2>v[5000];
int MAX=1e15;
int dp[51][51],h,w;
int dy[]={0,1};
int dx[]={1,0};
string s[99];
int f=0;
void make_graph(int y,int x){
  r(i,51)r(j,51)dp[i][j]=0;
  dp[y][x]=s[y][x]-'0';
  for(int i=y;i<h;i++){
    for(int j=x;j<w;j++)if(isdigit(s[i][j])&&dp[i][j]){
      r(k,2){
	int yy=i+dy[k];
	int xx=j+dx[k];
	if(yy<0||xx<0||yy>=h||xx>=w)continue;
	if(s[yy][xx]=='+')continue;
	r(l,2){
	  int yyy=yy+dy[l];
	  int xxx=xx+dx[l];
	  dp[yyy][xxx]=max(dp[yyy][xxx],dp[i][j]*(s[yyy][xxx]-'0'));
	}
      }
    }
  }
   for(int i=y;i<h;i++){
    for(int j=x;j<w;j++)if(isdigit(s[i][j])){
	v[y*100+x].push_back(P2(P(i,j),dp[i][j]));
	if(dp[i][j]>MAX)f++;
    }
  }
}
signed main(){
  cin>>h>>w;
  r(i,h)cin>>s[i];
  r(i,h)r(j,w)if(isdigit(s[i][j]))make_graph(i,j);
  memset(dp,0,sizeof(dp));
  dp[0][0]=s[0][0]-'0';
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(dp[i][j]>MAX)f++;
      r(k,2){
	int y=i+dy[k];
	int x=j+dx[k];
	if(y<0||x<0||y>=h||x>=w)continue;
	if(s[y][x]=='*')continue;
	r(l,2){
	  int yy=y+dy[l];
	  int xx=x+dx[l];
	  dp[yy][xx]=max(dp[yy][xx],dp[i][j]+s[yy][xx]-'0');
	}
      }
      r(k,v[i*100+j].size()){
	int y=v[i*100+j][k].first.first;
	int x=v[i*100+j][k].first.second;
	int cost=v[i*100+j][k].second;
	dp[y][x]=max(dp[y][x],dp[i][j]+cost-(s[i][j]-'0'));
      }
    }
  }
  if(f)cout<<-1<<endl;
  else cout<<dp[h-1][w-1]<<endl;
}