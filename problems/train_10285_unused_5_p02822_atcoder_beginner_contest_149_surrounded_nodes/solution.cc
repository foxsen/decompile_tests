#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pcc pair<char,char>
#define vi vector <int>
#define vl vector <ll>
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define pd(x) printf("%d",x)
#define plld(x) printf("%lld",x)
#define pds(x) printf("%d ",x)
#define pllds(x) printf("%lld ",x)
#define pdn(x) printf("%d\n",x)
#define plldn(x) printf("%lld\n",x)
#define INF 2e9
#define INFLL 4e18
using namespace std;
ll powmod(ll base,ll exponent,ll mod){ // with mod < 1e9
	ll ans=1;
	while(exponent){
		if(exponent&1)ans=(ans*base)%mod;
		base=(base*base)%mod;
		exponent/=2;
	}
	return ans;
}
ll gcd(ll a, ll b){
	if(b==0) return a;
	else return gcd(b,a%b);
}
const int upperlimit = 2e5+1;
const int mod = 1e9+7;
int subtr[upperlimit];
bool visited[upperlimit];
vi adj[upperlimit];
void dfs(int node){
	visited[node]=true;
	subtr[node]=1;
	for(int i = 0; i < adj[node].size(); i++){
		if(! visited[adj[node][i]]){
			dfs(adj[node][i]);
			subtr[node]+=subtr[adj[node][i]];
		}
	}
}
int main() {
	int n,a,b;
	sd(n);
	ll ans=0;
	for(int i = 1; i < n; i++){
		sd(a);sd(b);
		adj[a].pb(b);adj[b].pb(a);
	}
	dfs(1);
	for(int i = 1; i <= n; i++){
		ll calc=powmod(2,n-1,mod)-1;
		for(int j = 0; j < adj[i].size(); j++){
			if(subtr[adj[i][j]]<subtr[i]) calc-=powmod(2,subtr[adj[i][j]],mod)-1;
			else calc-=powmod(2,n-subtr[i],mod)-1;
			if(calc<0) calc+=mod;
		}
		ans+=calc;ans%=mod;
	}
	ans*=powmod(2,mod-1-n,mod);ans%=mod;
	plld(ans);
	return 0;
}