#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define FORR(i,a,b) for(int i=(b)-1; i>=(a); i--)

#define DEBUG(x) cerr << #x << ": " << (x) << endl;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

const ll MOD = 998244353;

ll modpow(ll a, ll b){
	ll r = 1;
	while(b){
		if(b&1)r=r*a%MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return r;
}
ll modinv(ll a){
	return modpow(a, MOD-2);
}
ll fact[425252];
ll ifact[425252];
ll comb(int a, int b){
	if(a<0 || b<0 || b>a)return 0ll;
	return fact[a]*ifact[b]%MOD*ifact[a-b]%MOD;
}

int n;
vi g1[252521];
vi g2[252521];

set<pii> g2s;

int main(){
	scanf("%d",&n);
	REP(i,n-1){
		int a,b;
		scanf("%d%d",&a,&b);--a;--b;
		g1[a].push_back(b);
		// g1[b].push_back(a);
	}
	REP(i,n-1){
		int a,b;
		scanf("%d%d",&a,&b);--a;--b;
		g2[a].push_back(b);
		g2[b].push_back(a);
		g2s.insert(pii(a,b));
		g2s.insert(pii(b,a));
	}
	if(n==1){
		puts("0");
		return 0;
	}
	// init
	fact[0] = 1;
	FOR(i,1,425252)fact[i] = i*fact[i-1]%MOD;
	ifact[425252-1] = modinv(fact[425252-1]);
	FORR(i,1,425252)ifact[i-1] = i*ifact[i]%MOD;
	// do
	ll ans = 0;
	REP(x,n+1){
		ll prob = comb(n,x) * modinv(modpow(2,n)) % MOD;
		ll add = prob * x % MOD * (n-x) % MOD;
		ans += add;
		ans %= MOD;
	}
	REP(x,n+1){
		ll prob = comb(n,x) * modinv(modpow(2,n)) % MOD;
		ll eprob = comb(n-2, x-2) * modinv(comb(n, x)) % MOD;
		ll trest = (n-1) * eprob % MOD;
		ll add = prob * (n-x) % MOD * trest % MOD;
		// DEBUG(add);
		ans += MOD - add * 2 % MOD;
		ans %= MOD;
	}
	ll inv16 = modinv(16);
	REP(u,n)for(int v : g1[u]){
		ll es = (n-1) - g2[u].size() - g2[v].size() + g2s.count(pii(u,v));
		ans += es * inv16 % MOD;
		ans %= MOD;
	}
	// REP(x,n+1){
	// 	double prob = comb(n, x) / pow(2.0, n);
	// 	double eprob = comb(n-2, x-2) / (double)comb(n, x);
	// 	double trest = (n-1) * eprob;
	// 	double eprob2 = comb(n-2, (n-x)-2) / (double)comb(n, n-x);
	// 	double trest2 = (n-1) * eprob;
	// 	double add = prob * trest * trest2;
	// 	DEBUG(add);
	// 	ans += add;
	// }
	printf("%lld\n",ans);
	return 0;
}

