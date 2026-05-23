#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <stdio.h>
#include <time.h>
#include <numeric>
#include <random>
#include <unordered_map>
#include <unordered_set>
#define all(a) a.begin(),a.end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define pb push_back
#define debug(x) cerr << __LINE__ << ' ' << #x << ':' << x << '\n'
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> P;
typedef complex<ld> com;
constexpr int inf = 1000000010;
constexpr ll INF = 1000000000000000010;
constexpr ld eps = 1e-12;
constexpr ld pi = 3.141592653589793238;
template<class T, class U> inline bool chmax(T &a, const U &b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmin(T &a, const U &b) { if (a > b) { a = b; return true; } return false; }

constexpr ll mod = 1000000007;
vector<ll> fac, inv, facinv;

void modcalc(int n) {
	fac.resize(n); inv.resize(n); facinv.resize(n);
	fac[0] = 1; fac[1] = 1; inv[1] = 1;
	facinv[0] = 1; facinv[1] = 1;
	for (ll i = 2; i < n; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = mod - inv[mod % i] * (mod / i) % mod;
		facinv[i] = facinv[i - 1] * inv[i] % mod;
	}
}

ll modinv(ll a) {
	a %= mod;
	if (a == 0) abort();
	if (a < (ll)inv.size()) return inv[a];
	ll b = mod, u = 1, v = 0;
	while (b) {
		ll t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= mod;
	if (u < 0) u += mod;
	return u;
}

ll modpow(ll a, ll b, ll m = mod) {
	ll ans = 1;
	a %= m;
	while (b) {
		if (b & 1) ans = ans * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return ans;
}

ll modcomb(ll n, ll k) {
	if (n < 0 || k < 0 || n < k) return 0;
	return fac[n] * facinv[k] % mod * facinv[n - k] % mod;
}

ll modperm(ll n, ll k) {
	if (n < 0 || k < 0 || n < k) return 0;
	return fac[n] * facinv[n - k] % mod;
}

ll modhom(ll n, ll k) {
	if (n < 0 || k < 0 || n == 0 && k > 0) return 0;
	if (n == 0 && k == 0) return 1;
	return fac[n + k - 1] * facinv[k] % mod * facinv[n - 1] % mod;
}

template<class T> class segtree {
	int n;
	vector<T> data;
	T id = 0;
	T operation(T a, T b) { return a + b; };
public:
	segtree(int _n) {
		n = 1;
		while (n < _n + 2) n <<= 1;
		data = vector<T>(2 * n, id);
	}
	void change(int i, T x) {
		i += n;
		data[i] = x;
		while (i > 1) {
			i >>= 1;
			data[i] = operation(data[i << 1], data[i << 1 | 1]);
		}
	}
	void add(int i, T x) { change(i, data[i + n] + x); }
	T get(int a, int b) {
		T left = id; T right = id;
		a += n; b += n;
		while (a < b) {
			if (a & 1) left = operation(left, data[a++]);
			if (b & 1) right = operation(data[--b], right);
			a >>= 1; b >>= 1;
		}
		return operation(left, right);
	}
	T get_all() { return data[1]; }
	T operator[](int i) { return data[i + n]; }
};

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	modcalc(500010);
	
	int n;
	cin >> n;
	vector<bool> ok(n);
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
		a[i]--;
		if (a[i] != -1) {
			ok[a[i]] = true;
		}
	}
	vector<int> vec;
	rep(i, n) if (!ok[i]) vec.pb(i);
	ll vs = vec.size();
	reverse(all(a));
	ll ans = 0, d = 0, zero = 0;
	segtree<ll> seg(n);
	rep(i, n) {
		ll p = 0;
		if (a[i] == -1) {
			p += zero * modinv(2) % mod;
			p += d;
			p %= mod;
			zero++;
		}
		else {
			if (vs) {
				p += zero * modinv(vs) % mod;
				ll idx = upper_bound(all(vec), a[i]) - vec.begin();
				p *= idx;
				p %= mod;
				d += mod + 1 - idx * modinv(vs) % mod;
				d %= mod;
			}
			p += seg.get(0, a[i]);
			seg.add(a[i], 1);
		}
		ans += p * fac[i] % mod;
	}
	ans %= mod; ans++;
	ans *= fac[vs]; ans %= mod;
	cout << ans << '\n';
}