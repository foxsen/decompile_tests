#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) printf("%lld ",i);puts("")
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ep emplace_back
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define fil(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pa;
typedef pair<ll,ll> PA;
typedef vector<int> poly;
inline ll read(){
    ll x=0,f=1;char c=getchar();
    while ((c<'0'||c>'9')&&(c!='-')) c=getchar();
    if (c=='-') f=-1,c=getchar();
    while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return x*f;
}

const int N = 35,inf = 1e9;
int n,m,q,tot,cnt[N],id[N][N];
ll pre[100010];
struct node{
	ll s,p,c;
}a[N][N];

namespace MCMF{
	const int N = 1010, M = 10010;
	int tot=-1,first[N],to[M<<1],last[M<<1];
	ll flow[M<<1],cost[M<<1];
	inline void init(){
		fil(first,-1);
	}
	inline void add(int x,int y,ll w,ll f){
		to[++tot]=y,flow[tot]=w,cost[tot]=f,last[tot]=first[x],first[x]=tot;
	}
	inline void Add(int x,int y,ll w,ll f){
		add(x,y,w,f),add(y,x,0,-f);
	}
	const ll inf = 1ll<<60;
	ll dis[N],Flow[N];
	int pre[N],pos[N];
	bool vis[N];
	inline bool spfa(int s,int t,int n){
		For(i,1,n) vis[i]=0,dis[i]=Flow[i]=inf;
		queue<int>q;q.push(s),dis[s]=0;
		while (!q.empty()){
			int u=q.front();q.pop(),vis[u]=0;
			for (int i=first[u];i!=-1;i=last[i]){
				int v=to[i];
				if (dis[u]+cost[i]<dis[v]&&flow[i]){
					dis[v]=dis[u]+cost[i],Flow[v]=min(Flow[u],flow[i]),pre[v]=u,pos[v]=i;
					if (!vis[v]) q.push(v),vis[v]=1;
				}
			}
		}
		return dis[t]!=inf;
	}
	inline vector<ll> solve(int S,int T,int n){
		vector<ll>ans;
		while (spfa(S,T,n)){
			if (Flow[T]>100000000) return ans.pb(dis[T]),ans;
			For(i,1,Flow[T]) ans.pb(dis[T]);
			for (int i=T;i!=S;i=pre[i]) flow[pos[i]]-=Flow[T],flow[pos[i]^1]+=Flow[T];
		}
		return ans;
	}
};

int main(){
	n=read();
	int S=1,T=2;
	tot=2,MCMF::init();
	For(i,1,n){
		cnt[i]=read(),id[i][0]=++tot;
		For(j,1,cnt[i]){
			a[i][j]=(node){read(),read(),read()};
			id[i][j]=++tot;
		}
		MCMF::Add(S,id[i][0],inf,0),MCMF::Add(id[i][cnt[i]],T,inf,0);
		sort(a[i]+1,a[i]+1+cnt[i],[](node a,node b){
			return a.s<b.s;
		});
		For(j,1,cnt[i]){
			MCMF::Add(id[i][j-1],id[i][j],a[i][j].p,0);
			MCMF::Add(id[i][j-1],id[i][j],1e9,a[i][j].c);
		}
	}
	m=read();
	while (m--){
		int u=read(),v=read(),w=read(),l=0;
		For(i,1,cnt[u]){
			while (l<cnt[v]&&a[v][l+1].s<=a[u][i].s+w) ++l;
			if (l==cnt[v]) break;
			MCMF::Add(id[v][l],id[u][i],1e9,0);
		}
	}
	auto p=MCMF::solve(S,T,tot);
	pre[0]=p[0];
	FOR(i,1,siz(p)) pre[i]=pre[i-1]+p[i];
	q=read();
	while (q--){
		ll A=read();
		int pos=lower_bound(all(p),A)-p.begin();
		if (pos==siz(p)) puts("-1");
			else printf("%lld\n",A*pos-(pos==0?0:pre[pos-1]));
	}
}