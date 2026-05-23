#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T,A,X,B,Y,C,D;
vector<pair<int,int> > s;
int _gcd(int a,int b){
	if(b==0)return a;
	return _gcd(b,a%b);
}
void init(){
	int g=_gcd(A,B);
	A/=g,B/=g,C/=_gcd(g,C);
	g=_gcd(A,C),A/=g,C/=g,Y/=g;
	g=_gcd(B,C),B/=g,C/=g,X/=g;
}
void exgcd(int a,int b,int &x,int &y){
	if(b==0){
		x=1,y=0;
		return;
	}
	exgcd(b,a%b,x,y);
	int t=x;
	x=y;
	y=t-a/b*y;
}
int Inv(int a,int mod){
	int x,y;
	exgcd(a,mod,x,y);
	return (x+mod)%mod;
}
int Get(int x){
	return !x?C:(C-1LL*x*D%C)%C;
}
void Get_seg(){
	D=1LL*A*Inv(B,C)%C;
	s.clear();
	int W=C,H=D,now=0,invD=Inv(D,C);
	while("MAK AK IOI!"){
		s.emplace_back(W/H,(int)(1LL*now*invD%C));
		now+=W/H*H;
		if(!(W%=H))break;
		if(!(H%=W))H=W;
	}
	s.emplace_back(0,C);
}
int main(){
	T=read();
	while(T--){
		A=read(),X=read(),B=read(),Y=read(),C=read();
		init();
		if(C==1){
			printf("%d\n",X+Y);
			continue;
		}
		Get_seg();
		ll mx=0;
		for(int i=0;i<(int)s.size()-1;++i){
			int lx=s[i].second,rx=s[i+1].second;
			int ly=Get(lx),ry=Get(rx);
			int dx=(rx-lx)/s[i].first,dy=(ly-ry)/s[i].first;
			auto check=[=](ll k) -> bool{
				if(X-k*lx<0||Y-k*ry<0)return false;
				int a=(X-k*lx)/dx,b=(Y-k*ry)/dy;
				return a+b>=k*s[i].first;
			};
			ll l=0,r=X+Y+1,ans=0;
			while(l<r){
				ll mid=(l+r)>>1;
				if(check(mid)){
					ans=mid;
					l=mid+1;
				}
				else{
					r=mid;
				}
			}
			mx=max(mx,ans);
		}
		printf("%lld\n",mx);
	}
	return 0;
}

