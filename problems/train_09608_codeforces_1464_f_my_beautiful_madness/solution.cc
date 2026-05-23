#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define poly vector<ll>
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
inline ll read(){
	ll x=0; char ch=getchar(); bool d=1;
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') d=0;
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	return d?x:-x;
}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=2e5+5;
int FA[20][N],SON[N],son[N],dep[N],mx[N],fa[N],size[N];
poly v[N];
void dfs(int u){
	dep[u]=dep[fa[u]]+1; mx[u]=dep[u]; size[u]=1;
	for(auto k:v[u]){
		if(k==fa[u]) continue;
		FA[0][k]=fa[k]=u; dfs(k); size[u]+=size[k];
		mx[u]=max(mx[u],mx[k]);
		if(!SON[u]||mx[k]>mx[SON[u]]) SON[u]=k;
		if(!son[u]||size[k]>size[son[u]]) son[u]=k;
	}
}
int dfn[N],TOP[N],top[N],st[N],ed[N],cnt;
poly up[N],dw[N];
void dfs1(int u,int t){
	TOP[u]=t;
	if(u==t){
		int x=u;
		For(i,0,mx[u]-dep[u]) up[u].pb(x),x=fa[x];
		x=u;
		For(i,0,mx[u]-dep[u]) dw[u].pb(x),x=SON[x];
	}
	if(SON[u]) dfs1(SON[u],t);
	for(auto k:v[u]){
		if(k==fa[u]||k==SON[u]) continue;
		dfs1(k,k);
	}
}
void dfs2(int u,int t){
	top[u]=t; st[u]=++cnt; dfn[cnt]=u;
	if(son[u]) dfs2(son[u],t);
	for(auto k:v[u]){
		if(k==fa[u]||k==son[u]) continue;
		dfs2(k,k);
	}
	ed[u]=cnt;
}
int alb[N];
int findk(int u,int k){
	if(dep[u]<=k) return 1;
	if(!k) return u;
	u=FA[alb[k]][u]; k-=(1<<alb[k]);
	k-=dep[u]-dep[TOP[u]]; u=TOP[u];
	return k<0?dw[u][-k]:up[u][k];
}
int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}
int D(int x,int y){
	assert(x>0); assert(y>0);
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}
void init(int n){
	dfs(1); dfs1(1,1); dfs2(1,1);
	For(i,2,n) alb[i]=alb[i>>1]+1;
	For(i,1,18){
		For(j,1,n) FA[i][j]=FA[i-1][FA[i-1][j]];
	}
}
pii MX(pii a,pii b){
	if(a.fi==0) return b;
	if(b.fi==0) return a;
	if(D(a.fi,a.se)>D(b.fi,b.se)) return a;
	return b;
}
pii operator +(pii a,pii b){
	if(a.fi==0) return b;
	if(b.fi==0) return a;
	pii res=MX(a,b);
	res=MX(res,mp(a.fi,b.se));
	res=MX(res,mp(a.se,b.se));
	res=MX(res,mp(a.fi,b.fi));
	res=MX(res,mp(a.se,b.fi));
	return res;
}
struct tree{
	int sum[N<<2];
	pii t[N<<2];
	void change(int k,int l,int r,int pos,int x){
		if(l==r){
			sum[k]+=x;
			if(sum[k]) t[k]=mp(dfn[l],dfn[l]);
			else t[k]=mp(0,0);
			return;
		}
		int mid=l+r>>1;
		if(pos<=mid) change(k<<1,l,mid,pos,x);
		else change(k<<1|1,mid+1,r,pos,x);
		t[k]=t[k<<1]+t[k<<1|1];
	}
	pii find(int k,int l,int r,int L,int R){
		if(l>=L&&r<=R) return t[k];
		int mid=l+r>>1;
		if(R<=mid) return find(k<<1,l,mid,L,R);
		if(L>mid) return find(k<<1|1,mid+1,r,L,R);
		return find(k<<1,l,mid,L,R)+find(k<<1|1,mid+1,r,L,R);
	}
}T;
int sum[N<<2];
void change(int k,int l,int r,int pos,int x){
	if(l==r){
		sum[k]+=x; return;
	}
	int mid=l+r>>1;
	if(pos<=mid) change(k<<1,l,mid,pos,x);
	else change(k<<1|1,mid+1,r,pos,x);
	sum[k]=sum[k<<1]+sum[k<<1|1];
}
int find(int k,int l,int r,int L,int R){
	if(l>=L&&r<=R) return sum[k];
	int mid=l+r>>1;
	if(R<=mid) return find(k<<1,l,mid,L,R);
	if(L>mid) return find(k<<1|1,mid+1,r,L,R);
	return find(k<<1,l,mid,L,R)+find(k<<1|1,mid+1,r,L,R);
}
multiset<pii,greater<pii>> S;
bool check(int n,int d){
	int u=findk((*S.begin()).se,d),t=findk(u,d);
	if(find(1,1,n,st[t],ed[t])!=S.size()) return 0;
	pii ssw=T.find(1,1,n,st[t],ed[t]);
	assert(ssw.fi>0); assert(ssw.se>0);
	assert(u>0); assert(t>0);
	// cout<<"mjn "<<ssw.fi<<" "<<ssw.se<<" "<<t<<endl;
	int ksg=max(D(u,ssw.fi),D(u,ssw.se));
	return ksg<=d;
}
int main(){
	int n=read(),m=read();
	For(i,1,n-1){
		int x=read(),y=read();
		v[x].pb(y); v[y].pb(x);
	}
	init(n);
	For(i,1,m){
		int op=read();
		if(op==1){
			int x=read(),y=read(),t=lca(x,y);
			change(1,1,n,st[x],1); change(1,1,n,st[y],1);
			change(1,1,n,st[t],-1); T.change(1,1,n,st[t],1);
			S.insert(mp(dep[t],t));
		}else if(op==2){
			int x=read(),y=read(),t=lca(x,y);
			change(1,1,n,st[x],-1); change(1,1,n,st[y],-1);
			change(1,1,n,st[t],1); T.change(1,1,n,st[t],-1);
			S.erase(S.find(mp(dep[t],t)));
		}else puts(check(n,read())?"Yes":"No");
	}
}