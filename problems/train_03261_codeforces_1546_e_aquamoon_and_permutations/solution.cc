#include<bits/stdc++.h> 
using namespace std;
namespace Ruri{
    #define ms(a,b) memset(a,b,sizeof(a))
    #define repi(i,a,b) for(int i=a,bbb=b;i<=bbb;++i)//attention reg int or reg ll ?
    #define repd(i,a,b) for(int i=a,bbb=b;i>=bbb;--i)
    #define reps(s) for(int i=head[s],v=e[i].to;i;i=e[i].nxt,v=e[i].to)
    #define ce(i,r) i==r?'\n':' '
    #define pb push_back 
    #define all(x) x.begin(),x.end()
    #define gmn(a,b) a=min(a,b)
    #define gmx(a,b) a=max(a,b)
    #define fi first
    #define se second                         
    typedef long long ll;
    typedef unsigned long long ull;
    typedef double db;
    const int infi=1e9;//infi较大，注意涉及inf相加时爆int
    const ll infl=4e18;
    inline ll ceil_div(ll a,ll b){ return (a+b-1)/b; }
    inline ll pos_mod(ll a,ll b){ return (a%b+b)%b; }
    //std::mt19937 rnd(time(0));//std::mt19937_64 rnd(time(0));
}
using namespace Ruri;
namespace Read{
    #define ss(a) scanf("%s",a)
    inline int ri(){ int x; scanf("%d",&x); return x; }
    inline ll rl(){ ll x;  scanf("%lld",&x); return x; }
    inline db rd(){ db x; scanf("%lf",&x); return x; }
}
namespace DeBug{
    #define pr(x) cout<<#x<<": "<<(x)<<endl
    #define pra(x,a,b) cout<<#x<<": "<<endl; \
            repi(i,a,b) cout<<x[i]<<" ";     \
            puts("");   
    #define FR(a) freopen(a,"r",stdin)
    #define FO(a) freopen(a,"w",stdout)
}
using namespace Read;
using namespace DeBug;
const int MAX_N=5e2+5;
const int mod=998244353;
int n,a[MAX_N<<1][MAX_N];
int choose[MAX_N<<1];
int cnt[MAX_N];
void Mark(int row)
{
	choose[row]=1;
	repi(i,1,2*n)if(!choose[i])repi(j,1,n)if(a[i][j]==a[row][j]){
		choose[i]=-1; break;
	}
}
bool Find()
{
	repi(j,1,n){
		repi(i,1,n) cnt[i]=0;
		repi(i,1,2*n)if(!choose[i]) ++cnt[a[i][j]];
		int tmp=0;
		repi(i,1,n)if(cnt[i]==1){ tmp=i; break; }
		if(!tmp) continue;
		repi(i,1,2*n)if(!choose[i]&&a[i][j]==tmp){ tmp=i; break; }
		Mark(tmp);
		return true;
	}
	return false;
}
int g[MAX_N<<1][MAX_N<<1];
int color[MAX_N<<1];
void Dfs(int u,int c)
{
	color[u]=c;
	repi(i,1,2*n)if(g[u][i]&&!color[i]) Dfs(i,c*-1);
}
void Solve()
{
	repi(i,1,2*n) choose[i]=0;
	while(Find()) ;
	repi(i,1,2*n) color[i]=0;
	repi(i,1,2*n)repi(j,1,2*n) g[i][j]=0;
	repi(i,1,2*n)if(!choose[i])repi(j,i+1,2*n)if(!choose[j]){
		bool flag=false;
		repi(k,1,n)if(a[i][k]==a[j][k]){ flag=true; break; }
		if(flag) g[i][j]=g[j][i]=true;
	}
	int tot=1;
	repi(i,1,2*n)if(!choose[i]&&!color[i]) Dfs(i,1),tot=2ll*tot%mod;
	printf("%d\n",tot);
	repi(i,1,2*n)if(choose[i]==1||color[i]==1) printf("%d ",i);
	puts("");
}
int main()
{
	int T=ri();
	while(T--)
	{
		n=ri();
		repi(i,1,2*n)repi(j,1,n) a[i][j]=ri();
		Solve();
	}
    return 0;
}
