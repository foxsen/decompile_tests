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

const int cys=998244353;
int n;
ll a[300005],fac[300005],inv[300005],hv[300005];
bool vis[300005];
vector<int> v;

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int main(){
	n=readint();
	fac[0]=inv[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%cys;
	inv[n]=qpow(fac[n],cys-2);
	for(int i=n-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%cys;
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		int cnt=0;
		for(int u=i;!vis[u];u=a[u]) cnt++,vis[u]=1;
		v.pb(cnt);
	}
	sort(v.begin(),v.end());
	if(v[0]>2) return printf("0\n"),0;
	if(v[0]==1){
		ll ans=1;
		for(int i=0;i<v.size();){
			int num=v[i],cr=0;
			while(v[i]==num) cr++,i++;
			if(num>1){
				ll tmp=0;
				for(int j=1;j<=cr;j++)
					tmp=(tmp+fac[cr-1]*inv[j-1]%cys*inv[cr-j]%cys*qpow(cr,cr-j)%cys*qpow(hv[num],j)%cys*qpow(num,cr-j))%cys;
				ans=ans*tmp%cys;
			}
			else ans=cr==1?1:qpow(cr,cr-2);
			for(int j=num<<1;j<=n;j+=num) hv[j]+=cr*num;
		}
		printf("%lld\n",ans);
	}
	else{
		ll ans=1;
		for(int i=0;i<v.size();){
			int num=v[i],cr=0;
			while(v[i]==num) cr++,i++;
			if(num>2){
				ll tmp=0;
				for(int j=1;j<=cr;j++)
					tmp=(tmp+fac[cr-1]*inv[j-1]%cys*inv[cr-j]%cys*qpow(cr,cr-j)%cys*qpow(hv[num],j)%cys*qpow(num,cr-j))%cys;
				ans=ans*tmp%cys;
			}
			else ans=qpow(cr,cr-1)*qpow(num,cr-1)%cys;
			for(int j=num<<1;j<=n;j+=num) hv[j]+=cr*num;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
