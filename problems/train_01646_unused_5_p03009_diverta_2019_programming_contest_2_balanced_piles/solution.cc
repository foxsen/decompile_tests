#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include <bits/stdc++.h>
using namespace std;
template<class t> inline t read(t &x){
	char c=getchar();bool f=0;x=0;
	while(!isdigit(c)) f|=c=='-',c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	if(f) x=-x;return x;
}
template<class t,class ...A> inline void read(t &x,A &...a){
	read(x);read(a...);
}
template<class t> inline void write(t x){
	if(x<0) putchar('-'),write(-x);
	else{if(x>9) write(x/10);putchar('0'+x%10);}
}

const int mod=1e9+7,N=1e6+5;
int pre[N],f[N],fac[N],sum,n,h,d;

int calc(int l,int r){
	return l>0?(pre[r]-pre[l-1]+mod)%mod:pre[r];
}

signed main(){
	read(n,h,d);
	fac[0]=1;for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod,sum=(sum+fac[i])%mod;
	pre[0]=f[0]=fac[n];
	for(int i=1;i<h;i++){
		f[i]=1ll*calc(i-d,i-1)*sum%mod;
		pre[i]=(pre[i-1]+f[i])%mod;
	}
	write(calc(h-d,h-1));
}