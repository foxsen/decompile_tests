#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=25e4+10,mo=23333333333333333,M=2e7+3;
ll pw[N],ny[N];
ll n,S,v[N],ans;
char s[N];
ll mul(ll a,ll b){
	ll c=(long double)a*b/mo,z=a*b-c*mo;
	return  z<0?z+mo:z<mo?z:z-mo;
}
ll power(ll a,ll b=mo-2){
	ll ans=1;
	while (b){
		if (b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}return ans;
}
ll base(int p){
	return p<0?ny[-p]:pw[p];
}
map<ll,int> h;
int main(){
	cin>>n;
	pw[0]=ny[0]=1;
	pw[1]=(1e6+7),ny[1]=power(pw[1]);
	for (int i=2;i<=n;i++)
		pw[i]=mul(pw[i-1],pw[1]),
		ny[i]=mul(ny[i-1],ny[1]);
	int p=0;
	scanf("%s",s+1);
	for (int i=1;i<=n;i++){
		if (s[i]=='+')S=(S+base(p))%mo;
		if (s[i]=='-')S=(S-base(p)+mo)%mo;
		if (s[i]=='<')p--;
		if (s[i]=='>')p++;
		h[S]++;
		v[i]=S;
	}
//	cout<<S<<endl;
	ll a=1,b=0,ia=1;
	for (int i=1;i<=n;i++){
		ll s1=mul((S-b+mo)%mo,ia);
		ans+=h[s1];
		h[v[i]]--;
		if (s[i]=='+')b=(b-1+mo)%mo;
		if (s[i]=='-')b=(b+1)%mo;
		if (s[i]=='<')a=mul(a,pw[1]),b=mul(b,pw[1]),ia=mul(ia,ny[1]);
		if (s[i]=='>')a=mul(a,ny[1]),b=mul(b,ny[1]),ia=mul(ia,pw[1]);
//		cout<<ans<<endl;
	}
	cout<<ans<<endl;
}