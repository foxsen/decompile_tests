#include<bits/stdc++.h>
#define to edge[i].v
#define mp make_pair
#define rint register int
#define debug(x) cerr<<#x<<"="<<x<<endl
#define fgx cerr<<"-------------"<<endl
#define N 1000000
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
int D,head[N],tot,dep[N],mx[N];
struct E{int u,v;E(int _u=0,int _v=0):u(_u),v(_v){}}e[N];
struct Edge{int v,next;Edge(int _v=0,int _n=0):v(_v),next(_n){}}edge[N];
inline void add(int x,int y){edge[++tot]=Edge(y,head[x]);head[x]=tot;}
void dfs(int x,int la,int son=0)
{	for(rint i=head[x];i;i=edge[i].next)
	if(to!=la) dep[to]=dep[x]+1,dfs(to,x),son++;
	mx[dep[x]]=max(mx[dep[x]],son); D=max(D,dep[x]);
}
pll solve1(int x)
{	ll ans=1; memset(mx,0,sizeof(mx));
	dep[x]=D=1; dfs(x,0);
	for(rint i=1;i<D;i++) ans*=mx[i];
	return mp(D,ans);
}
pll solve2(int x)
{	ll ans=2; memset(mx,0,sizeof(mx));
	dep[e[x].u]=D=1; dfs(e[x].u,e[x].v); dep[e[x].v]=1; dfs(e[x].v,e[x].u);
	for(rint i=1;i<D;i++) ans*=mx[i];
	return mp(D,ans);
}
int main()
{	int n,x,y; cin>>n; pll ans=mp(1e18,1e18); 
	for(rint i=1;i<n;i++) scanf("%d%d",&x,&y),e[i]=E(x,y),add(x,y),add(y,x);
	for(rint i=1;i<=n;i++) ans=min(ans,solve1(i));
	for(rint i=1;i<n;i++) ans=min(ans,solve2(i));
	printf("%lld %lld",ans.first,ans.second);
	return 0;
}
