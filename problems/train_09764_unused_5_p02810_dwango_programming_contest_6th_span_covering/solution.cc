/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int mod = 1e9 + 7;

ll add(ll x, ll y) {
	x += y;
	if (x >= mod) {
		x -= mod;
	}
	return x;
}

ll sub(ll x, ll y) {
	x -= y;
	if (x < 0) {
		x += mod;
	}
	return x;
}

ll mul(ll x, ll y) {
	x *= y;
	return x % mod;
}

ll pwr(ll x, ll e) {
	ll res = 1;
	while (e) {
		if (e & 1) {
			res = mul(res, x);
		}
		x = mul(x, x);
		e /= 2;
	}
	return res;
}

const int X = 510;

int a[X], choose[X][X], pre_pwr[X][X];
ll dp[2][X][X];

int main() {
	fast_cin();
	int n, x;
	cin >> n >> x;
	for (int i = 1; i <= n; ++i) {
		int l; cin >> l;
		++a[l];
	}
	for (int i = 0; i <= x; ++i) {
		choose[i][0] = choose[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			choose[i][j] = add(choose[i - 1][j], choose[i - 1][j - 1]);
		}
	}
	for (int i = 0; i <= x; ++i) {
		pre_pwr[i][0] = 1;
		for (int j = 1; j <= n; ++j) {
			pre_pwr[i][j] = mul(pre_pwr[i][j - 1], i);
		}
	}
	dp[(x + 1) & 1][0][0] = 1;
	for (int i = x; i >= 1; --i) {
		memset(dp[i & 1], 0, sizeof(dp[i & 1]));
		auto cur = dp[i & 1], prv = dp[(i + 1) & 1];
		for (int sum = 0; sum <= x; ++sum) {
			int max_cnt = sum / i;
			for (int cnt = 0; cnt <= max_cnt; ++cnt) {
				for (int c = 0; c <= cnt; ++c) {
					cur[sum][cnt] = add(cur[sum][cnt], mul(prv[sum - i * c][cnt - c], choose[cnt][c]));
				}
				cur[sum][cnt] = mul(cur[sum][cnt], pre_pwr[sum - (i - 1) * cnt][a[i]]);
			}
		}
	}
	ll ans = 0;
	for (int sum = 0; sum <= x; ++sum) {
		for (int cnt = 0; cnt <= sum; ++cnt) {
			ll val = mul(dp[1][sum][cnt], choose[x - sum + 1][cnt]);
			ans = add(ans, mul(pwr(mod - 1, (x - sum) & 1), val));
		}
	}
	cout << ans << endl;
}