#include <bits/stdc++.h>

#define ss second
#define ff first
#define N 200005
#define ll long long
#define mod 1000000007
#define pb push_back
#define inf 1000000009
#define mid(a,b) (a+b)/2
#define pii pair<int,int>

using namespace std;

ll n,k;
ll ans,fact[2 * N];

ll der(ll a,ll b){
	if(b == 0) return 1;
	ll x = der(a,b / 2);
	if(b % 2) return (((x * x) % mod) * a) % mod;
	return (x * x) % mod;
}

ll C(ll n,ll k){
	return (fact[n] * der((fact[n - k] * fact[k]) % mod,mod - 2)) % mod;
}

ll num(ll n,ll k){
	k -= n;
	return C(n + k - 1,k);
}

int main()
{
	scanf("%lld%lld",&n,&k);
	fact[0] = 1;
	for(int i = 1;i <= n + min(n,k);i++)
		fact[i] = (fact[i - 1] * i) % mod;
	for(int i = 1;i <= min(k,n);i++){
		ans += (C(n,i) * num(n - i,n)) % mod;
		ans %= mod;
	}
	printf("%lld",ans + 1);
}