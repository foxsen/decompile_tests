#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll;
const int inf = 0x3fffffff; const ll INF = 0x1fffffffffffffff; const double eps=1e-12;
void tostr(ll x,string& res){while(x)res+=('0'+(x%10)),x/=10; reverse(ALL(res)); return;}
template<class T> inline bool chmax(T& a,T b){ if(a<b){a=b;return 1;}return 0; }
template<class T> inline bool chmin(T& a,T b){ if(a>b){a=b;return 1;}return 0; }
//end

int n,m,g[710][710];
int col[710], cnt[2];
bitset<710> dp;

void dfs(int x,int c){
   if(col[x]==-1)col[x]=c;
   else if(col[x]!=c){puts("-1"); exit(0);}
   else return;
   cnt[c]++;
   rep(nxt,0,n)if(g[x][nxt]&&x!=nxt)dfs(nxt,c^1);
}

int main(){
   scanf("%d%d",&n,&m);
   fill(g[0],g[n],1);
   rep(i,0,m){
      int x,y; scanf("%d%d",&x,&y); x--; y--;
      g[x][y]=g[y][x]=0;
   }
   dp=1; memset(col,-1,sizeof(col));
   rep(i,0,n)if(col[i]==-1){
      cnt[0]=cnt[1]=0; dfs(i,0);
      dp=(dp<<cnt[0])|(dp<<cnt[1]);
   }
   ll res=INF;
   rep(i,0,n)if(dp[i])chmin(res,1LL*i*(i-1)/2+1LL*(n-i)*(n-i-1)/2);
   printf("%lld\n",res);
   return 0;
}