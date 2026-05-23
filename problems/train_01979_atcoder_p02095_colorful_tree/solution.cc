#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,tot,now;
int v[200005],nxt[200005],h[100005],siz[100005],f[200005],son[100005],col[200005],a[100005],b[100005],ans[100005];
bool vis[200005];
vector<int> gar;

int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs1(int u,int fa){
	siz[u]=1;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dfs1(v[p],u);
		if(siz[v[p]]>siz[son[u]]) son[u]=v[p];
		siz[u]+=siz[v[p]];
	}
}

void change(int x,int y){
	if(!col[x]) gar.pb(x),col[x]=1;
	if(!col[y]) gar.pb(y),col[y]=1;
	int fx=getf(x),fy=getf(y);
	if(fx==fy){
		if(!vis[fx]) now++,vis[fx]=1;
		return;
	}
	f[fx]=fy;
	if(!vis[fx]&&!vis[fy]){
		now++;
		return;
	}
	if(vis[fx]&&vis[fy]) return;
	vis[fy]=1,now++;
}

void add(int u,int fa){
	change(a[u],b[u]);
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		add(v[p],u);
	}
}

void dfs2(int u,int fa,bool kp){
	for(int p=h[u];p;p=nxt[p]) if(v[p]!=fa&&v[p]!=son[u]) dfs2(v[p],u,0);
	if(son[u]) dfs2(son[u],u,1);
	for(int p=h[u];p;p=nxt[p]) if(v[p]!=fa&&v[p]!=son[u]) add(v[p],u);
	change(a[u],b[u]);
	ans[u]=now;
	if(!kp){
		for(auto x:gar) f[x]=x,vis[x]=0,col[x]=0;
		gar.clear();
		now=0;
	}
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=m;i++) f[i]=i;
	for(int i=1;i<n;i++) addedge(readint(),readint());
	for(int i=1;i<=n;i++) a[i]=readint(),b[i]=readint();
	dfs1(1,-1);
	dfs2(1,-1,1);
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}
