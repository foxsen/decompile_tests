#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;
const int mod=1e9+7;
const int inf=1e9;
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int,int> pii;
ll qpow(ll a,ll b){ll ans=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)ans=ans*a%mod;a=a*a%mod;}return ans;}
ll gcd(ll a,ll b){return b>0?gcd(b,a%b):a;}
int n,m,T;
int a[maxn],d[maxn];

vi g[maxn],dis[maxn],val[maxn];
int pre[maxn],mx[maxn];
bool vis[maxn];
namespace dfz{
	int MX,SZ,root;
	int sz[maxn];
	int mxson[maxn];
	void getRoot(int u,int fa){
		sz[u]=1;mxson[u]=0;
		for(auto v:g[u]){
			if(v==fa||vis[v]) continue;
			getRoot(v,u);
			sz[u]+=sz[v];
			mxson[u]=max(mxson[u],sz[v]);
		}
		mxson[u]=max(mxson[u],SZ-sz[u]);
		if(mxson[u]<MX) {
			root = u;
			MX=mxson[u];
		}
	}
	void dfs(int u,int fa,int dep,int rt){
		dis[u].pb(dep);
		for(auto v:g[u]){
			if(v==fa||vis[v]) continue;
			dfs(v,u,dep+1,rt);
		}
		mx[rt]=max(mx[rt],dep);
	}
	void divide(int rt){
		vis[rt]=1;
		for(auto v:g[rt]){
			if(vis[v]) continue;
			SZ=sz[v];
			root=0;
			MX=inf;
			getRoot(v,v);
			pre[root]=rt;
			divide(root);
		}
		vis[rt]=0;
		dfs(rt,rt,0,rt);
		return;
	}
}

int main() {
	scanf("%d",&n); 
	for(int i=1;i<=n;i++) pre[i]=i;
	for(int u,v,i=1;i<=n-1;i++){
		scanf("%d%d",&u,&v);
		g[u].pb(v);
		g[v].pb(u);
	}
	scanf("%d",&m);
	queue<int>q;
	for(int temp,i=1;i<=m;i++){
		scanf("%d",&temp);
		q.push(temp);
		d[temp]=0;
		vis[temp]=1;
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		for(auto v:g[u]){
			if(vis[v])continue;
			d[v]=d[u]+1;
			vis[v]=1;
			q.push(v);
		}
	}
	for(int i=1;i<=n;i++) vis[i]=0;
	dfz::MX=inf;
	dfz::SZ=n;
	dfz::getRoot(1,1);
	dfz::divide(dfz::root);
	for(int i=1;i<=n;i++) val[i]=vi(mx[i]+1,0);
	for(int i=1;i<=n;i++){
		int u=i;
		for(auto x:dis[i]){
			if(x<d[i]){
				int temp=min(d[i]-1-x, (int)val[u].size() -1);
				val[u][temp]=max(val[u][temp],d[i]);
			}
			u=pre[u];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=val[i].size()-2;j>=0;j--){
			val[i][j]=max(val[i][j],val[i][j+1]);
		}
	}
	for(int ans,i=1;i<=n;i++){
		int u=i;
		ans=0;
		for(auto x:dis[i]){
			ans=max(ans,val[u][x]);
			u=pre[u];
		}
		if(d[i]==0){
			ans=0;
		}
		printf("%d%c", ans, " \n"[i==n]);
	}
	return 0;
}
/*
13
1 2
2 3
3 4
3 5
3 6
4 7
4 8
5 9
5 10
6 11
6 12
11 13
3
7 9 13
*/