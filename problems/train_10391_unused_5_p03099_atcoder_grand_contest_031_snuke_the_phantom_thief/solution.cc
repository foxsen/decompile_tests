#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const ll N=1005,inf=1e18,M=1e6;
ll w[M],ne[M],la[M],len[M],cst[M],t=1;
ll d[M],dep[M],s[M],ans,S,T,vis[M],cur[M];
void alink(ll x,ll y,ll z,ll l){
	w[++t]=y;
	ne[t]=la[x];
	la[x]=t;
	len[t]=z;
	cst[t]=l;
}
void link(ll x,ll y,ll z,ll l){
	alink(x,y,z,l);
	alink(y,x,0,-l);
}
void clear(){
	for (ll i=1;i<=T;i++)la[i]=0;
	t=1;
}
ll spfa(){
	for (ll i=1;i<=T;i++)s[i]=-inf,vis[i]=0;
	ll l=0,r=1;
	s[S]=0,d[1]=S,vis[S]=1;
	while (l<r){
		ll x=d[++l];
		for (ll y=la[x];y;y=ne[y]){
			ll z=w[y];
			if (s[z]<s[x]+cst[y]&&len[y]){
				s[z]=s[x]+cst[y];
				if (!vis[z]){
					d[++r]=z;
					vis[z]=1;
				}
			}
		}
		vis[x]=0;
	}
	l=0,r=1;vis[S]=1;
	while (l<r){
		ll x=d[++l];
		cur[x]=la[x];
		for (ll y=la[x];y;y=ne[y]){
			ll z=w[y];
			if (s[z]==s[x]+cst[y]&&len[y]&&!vis[z]){
				dep[z]=dep[x]+1;
				vis[z]=1;
				d[++r]=z;
			}
		}
	}
	return vis[T];
}
ll flow(ll x,ll val){
	if (x==T)return val;
	ll v1=val;
	for (ll y=cur[x];y;cur[x]=y=ne[y]){
		ll z=w[y];
		if (dep[z]!=dep[x]+1||!len[y]||s[z]!=s[x]+cst[y])continue;
		ll use=flow(z,min(len[y],val));
		val-=use;
		len[y]-=use;
		len[y^1]+=use;
		ans+=use*cst[y];
		if (!val)return v1;
	}return v1-val;
}
ll n,px[N],py[N],val[N];
ll L[N],R[N],U[N],D[N];
ll ty[N],lim[N],lc[N],k;
ll z1[N],z2[N],c1[N],c2[N];
int main(){
	cin>>n;
	for (ll i=1;i<=n;i++)scanf("%lld%lld%lld",&px[i],&py[i],&val[i]);
	cin>>k;
	for (ll i=1;i<=k;i++){
		scanf("\n");
		ty[i]=getchar();
		scanf("%lld%lld",&lc[i],&lim[i]);
	}
	t=0;
	for (ll i=1;i<=n;i++)
		z1[i]=++t,z2[i]=++t,L[i]=0,R[i]=100,U[i]=100,D[i]=0,c1[i]=++t,c2[i]=++t;
	S=++t,T=++t;t=1;
	ll max1=0;
	for (ll K=1;K<=n;K++){
		for (ll i=1;i<=n;i++)
			L[i]=0,R[i]=100,U[i]=100,D[i]=0;
		ans=0;clear();
		for (ll i=1;i<=k;i++){
			if (ty[i]=='L'){
				for (ll j=lim[i]+1;j<=K;j++)
					L[j]=max(L[j],lc[i]+1);
			}
			if (ty[i]=='R'){
				for (ll j=1;j<=K-lim[i];j++)
					R[j]=min(R[j],lc[i]-1);
			}
			if (ty[i]=='U'){
				for (ll j=1;j<=K-lim[i];j++)
					U[j]=min(U[j],lc[i]-1);
			}
			if (ty[i]=='D'){
				for (ll j=lim[i]+1;j<=K;j++)
					D[j]=max(D[j],lc[i]+1);
			}
		}
		for (ll i=1;i<=K;i++)link(S,z1[i],1,0),link(z2[i],T,1,0);
		for (ll i=1;i<=K;i++){
			for (ll j=1;j<=n;j++){
				if (L[i]<=px[j]&&px[j]<=R[i])
					link(z1[i],c1[j],1,0);
				if (D[i]<=py[j]&&py[j]<=U[i])
					link(c2[j],z2[i],1,0);
			}
		}
		for (ll i=1;i<=n;i++)link(c1[i],c2[i],1,val[i]);
		while (spfa()){
			if (s[T]>0)flow(S,1<<30);
			else break;
		}
		max1=max(max1,ans);
	}
	cout<<max1<<endl;
}