#include<bits/stdc++.h>
#define fir first
#define sec second
#define db double
#define ll long long
#define ev eg[i].v
#define pb push_back
#define INF 1000000007
#define pir pair<int,int>
#define Rep(i,l,r) for(int i=(l);i<=(r);++i)
#define RepD(i,r,l) for(int i=(r);i>=(l);--i)
#define RepG(i,x) for(int i=hd[x];i;i=eg[i].nxt)
using namespace std;

const int N=1e5+5;

ll hd[N],cnt=0;bool vis[N];
struct Eg{ll v,nxt;}eg[N*2];
ll a[N],b[N],c[N],fa[N],f[N],g[N];

ll find(ll x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void add(ll u,ll v){eg[++cnt]=(Eg){v,hd[u]},hd[u]=cnt;}

bool cmp(ll x,ll y){return a[x]<a[y];}

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ll n,m;
	scanf("%lld%lld",&n,&m);
	Rep(i,1,n) scanf("%lld%lld",&a[i],&b[i]),a[i]=max(a[i]-b[i],0ll);
	Rep(i,1,m){
		ll u,v;
		scanf("%lld%lld",&u,&v);
		add(u,v),add(v,u);	
	}
	Rep(i,1,n) c[i]=fa[i]=i;
	sort(c+1,c+n+1,cmp);
	Rep(k,1,n){
		ll x=c[k];
		vis[x]=1,f[x]=a[x],g[x]=b[x];
		RepG(i,x)
			if(vis[ev]){
				ll ff=find(ev);
				if(x==ff) continue;
				fa[ff]=x,g[x]+=g[ff];
				f[x]=min(f[x],max(f[ff],a[x]-g[ff]));	
			}
	}
	printf("%lld\n",f[c[n]]+g[c[n]]);
	return 0;
}


