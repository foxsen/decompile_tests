#include<bits/stdc++.h>
#define ld double
#define ull unsigned long long
#define ll long long
#define pii pair<int,int >
#define iiii pair<int,pii >
#define mp make_pair
#define INF 1000000000
#define MOD 1000000007
#define rep(i,x) for(int (i)=0;(i)<(x);(i)++)
inline int getint(){
	int x=0,p=1;char c=getchar();
	while (c<=32)c=getchar();
	if(c==45)p=-p,c=getchar();
	while (c>32)x=x*10+c-48,c=getchar();
	return x*p;
}
using namespace std;
//ruogu_alter
const int N=2e5+5;
const int inv2=(MOD+1)/2;
int n,a[N],b[N],cnt[N],ib[N],pre[N],dx[N],dy[N];
//
inline void add(int &x,int y){
	x+=y;if(x>=MOD)x-=MOD;
}
inline void sub(int &x,int y){
	x-=y;if(x<0)x+=MOD;
}
inline int sub2(int x,int y){
	x-=y;
	return (x<0)?x+MOD:x;
}
inline int mul(int x,int y){
	ll ans=1ll*x*y;
	return ans%MOD;
}
inline int modpow(int x,int y){
	int ans=1;
	while(y){
		if(y&1)ans=mul(ans,x);
		x=mul(x,x);
		y>>=1;
	}
	return ans;
}
inline int modinv(int x){
	return modpow(x,MOD-2);
}
inline void upd(int x,int y){
	while(x<N){
		add(dy[x],y);
		dx[x]++;
		x+=x&-x;
	}
}	
inline int qry(int *d,int x){
	int ans=0;
	while(x){
		add(ans,d[x]);
		x-=x&-x;
	}
	return ans;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=getint();
	for(int i=1;i<=n;i++){
		a[i]=getint();
		cnt[a[i]]++;
	}
	for(int i=n-1;i>=1;i--)cnt[i]+=cnt[i+1];
	for(int i=1;i<=n;i++)cnt[i]-=n-i;
	for(int i=1;i<=n;i++)if(cnt[i]<=0){
		return !printf("%d\n",0);
	}
	int s=1;pre[0]=b[0]=1;
	for(int i=1;i<=n;i++)s=mul(s,cnt[i]);
	for(int i=1;i<=n;i++){
		b[i]=mul(cnt[i]-1,modinv(cnt[i]));
		if(!b[i])pre[i]=i,b[i]=b[i-1];
		else pre[i]=pre[i-1],b[i]=mul(b[i-1],b[i]);
		ib[i]=modinv(b[i]);
	}
	int res=0;
	for(int i=1;i<=n;i++){
		add(res,mul(b[a[i]],mul(s,mul(inv2,sub2(qry(dy,a[i]),qry(dy,pre[a[i]]-1))))));	
//		cout<<res<<endl;
		upd(a[i],ib[a[i]]);
	}
//	cout<<res<<endl;
	memset(dx,0,sizeof(dx));
	memset(dy,0,sizeof(dy));
	for(int i=n;i>=1;i--){
		sub(res,mul(b[a[i]],mul(s,mul(inv2,sub2(qry(dy,a[i]-1),qry(dy,pre[a[i]]-1))))));
		add(res,mul(s,qry(dx,a[i]-1)));
		upd(a[i],ib[a[i]]);
	}
	cout<<res<<endl;
	return 0;
}