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

const int N = 500 + 10;

ll a[N][N], f[N][N], b[N][N];
ll dp[N][N];

int main() {
	// cout << sizeof(dp) / 1e6 << endl;
	fast_cin();
	int n; cin >> n;
	ll sum = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i != j) {
				cin >> a[i][j];
				sum += a[i][j];
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			f[i][j] = f[i][j - 1] + a[j][i];
		}
		for (int j = i - 1; j >= 1; --j) {
			b[i][j] = b[i][j + 1] + a[i][j];
		}
	}
	ll ans = 0;
	for (int i = 1; i < n; ++i) {
		for (int j = i; j >= 0; --j) {
			for (int k = j; k >= 0; --k) {
				ll cost = dp[j][k] + f[i + 1][j] + b[i + 1][k + 1];
				dp[i + 1][j] = max(dp[i + 1][j], cost);
				dp[j][k] = cost;
				ans = max(ans, cost);
			}
		}
	}
	cout << sum - ans << endl;
}