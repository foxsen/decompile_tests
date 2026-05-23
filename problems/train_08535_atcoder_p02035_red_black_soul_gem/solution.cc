#include <bits/stdc++.h>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-9;
//const ll mod=1e9+7;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

const int M=2005;
ll n,mod,C[M][M];

ll Pow(ll x,ll p){
	ll r=1;
	for(;p>0;p>>=1){
		if(p&1) r=(r*x)%mod;
		x=(x*x)%mod;
	}
	return r;
}

int main(){
	cin>>n>>mod;
	C[0][0]++;
	for(int i=0;i<M-1;i++) for(int j=0;j<=i;j++){
		(C[i+1][j]+=C[i][j])%=mod;
		(C[i+1][j+1]+=C[i][j])%=mod;
	}
	ll res=0;
	for(ll i=1;i<n;i++){
		ll j=n-i,tmp=0;
		for(ll k=0;k<=j;k++){
			ll t=(k%2==0?1:mod-1);
			(t*=C[j][k])%=mod;
			(t*=Pow((Pow(2,j-k)-1+mod)%mod,i))%=mod;
			(tmp+=t)%=mod;
		}
		(tmp*=C[n][i])%=mod;
		(tmp*=Pow(2,i*(i-1)/2+j*(j-1)/2))%=mod;
		(res+=tmp)%=mod;
	}
	cout<<res<<endl;
}
