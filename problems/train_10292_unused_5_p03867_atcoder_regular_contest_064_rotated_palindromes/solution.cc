#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int INF = 1 << 30;

ll mod_pow(ll a, ll n) {
	if (n == 0) return 1;
	if (n % 2 == 0) {
		ll tmp = mod_pow(a, n / 2);
		return (tmp * tmp) % MOD;
	}
	return (a * mod_pow(a, n - 1)) % MOD;
}
ll cnt[10001];
int main() {
	int N, K;
	cin >> N >> K;
	vector<ll> div;
	for (ll i = 1; i*i <= N; i++) {
		if (N%i == 0) {
			div.push_back(i);
			if (i != N / i) div.push_back(N / i);
		}
	}
	sort(div.begin(), div.end());
	ll ans = 0;
	for (int i = 0; i < div.size(); i++) {
		cnt[i] = mod_pow(K, (div[i] + 1) / 2);
		for (int j = 0; j < i; j++) {
			if (div[i] % div[j] == 0) (cnt[i] += MOD - cnt[j]) %= MOD;
		}
		ll add = (cnt[i] * div[i]) % MOD;
		if (div[i] % 2 == 0) (add *= mod_pow(2, MOD - 2)) %= MOD;
		(ans += add) %= MOD;
	}
	cout << ans << endl;
}
