#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
#define ALL(C)     (C).begin(),(C).end()
#define pb         push_back
const int W = 20,H = 20;

int vol;
bool vis[H][W];
bool liv[H][W];
int    h[H][W];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};


void dfs(int r,int c,int y,int x,int water,bool &flag){
  if (x ==0 || y == 0 || x == c-1||y==r-1||liv[y][x]){
    flag=false;
  }
  if (vis[y][x])return ;
  vol+=water-h[y][x];
  vis[y][x]=true;
  
  rep(i,4){
    int nex=x+dx[i],ney=y+dy[i];
    if (nex == -1||ney==-1||nex==c||ney==r)continue;
    if (h[ney][nex] <water){
      dfs(r,c,ney,nex,water,flag);
    }
  }
  return;
}

bool compute(int r,int c,int C,int water){
  rep(i,r)rep(j,c)vis[i][j]=false;
  REP(i,1,r-1){
    REP(j,1,c-1){
      if (!vis[i][j] && h[i][j] < water){
	bool flag=true;
	vol=0;
	dfs(r,c,i,j,water,flag);
	if (flag&&vol >=C)return true;
      }
    }
  }
  return false;
}

bool check(int r,int c,int C){
  vector<int> val(r*c);
  rep(ii,r)rep(jj,c)val[ii*c+jj]=h[ii][jj];
  sort(ALL(val));
  val.erase(unique(ALL(val)),val.end());
  rep(ii,val.size())if (compute(r,c,C,val[ii]))return true;
  return false;
}

bool solve(int r,int c,int C){
  if (check(r,c,C))return true;
  rep(i,r){
    rep(j,c){
      if (liv[i][j])continue;
      h[i][j]++;
      if (check(r,c,C))return true;
      h[i][j]--;
    }
  }
  return false;
}

int main(){
  int r,c,C,R;
  while(cin>>r>>c>>C>>R && r){
    rep(i,r){
      rep(j,c){
	cin>>h[i][j];
	liv[i][j]=false;
      }
    }
    rep(i,R){
      int y,x;
      cin>>y>>x;y--;x--;
      liv[y][x]=true;
    }
    if (solve(r,c,C))cout <<"Yes"<<endl;
    else cout << "No"<<endl;
  }
  return false;
}