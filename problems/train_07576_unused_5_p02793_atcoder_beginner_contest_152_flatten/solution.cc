#include <bits/stdc++.h>
#define gmax(x,y) x=max(x,y)
using namespace std;

const int MOD = 1e9 + 7; 
typedef long long ll;

int mul(int x,int y){
	return (1LL*x*y) % MOD;
}

int modpow(int x,int p){
	int res = 1;
	while(p){
		if(p&1)res = mul(res,x);
		x = mul(x,x);
		p/=2;
	}
	return res;
}

int inv(int x){
	return modpow(x, MOD - 2);
}

int add(int x,int y){
	return (x + y) % MOD;
}

const int N = 1e6 + 5;

int cnt[N];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0;i < n; ++i){
		cin >> a[i];	
		int x = a[i];
		for(int d = 2; d * d <= x; ++d){
			int tcnt = 0;
			while(x % d == 0){
				++tcnt;	
				x/=d;
			}
			gmax(cnt[d], tcnt);
		}
		if(x != 1){
			gmax(cnt[x], 1);	
		}
	}
	int lcm = 1;
	for(int i = 2;i < N; ++i){
		lcm = mul(lcm, modpow(i,cnt[i]));
	}
	int ans = 0;
	for(int i = 0;i < n; ++i){
		ans = add(ans, mul(lcm, inv(a[i])));
	}
	cout << ans << '\n';
}
