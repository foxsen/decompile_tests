#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
#define INF 1<<30
#define LINF 1LL<<60
#define MAX_C 105
#define Min 10010
ll dp[MAX_C][Min];
int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	ll N, C; cin >> N >> C;
	vector<ll> a(N), b(N), c(N);
	for (int i = 0; i < N;i++) {
		cin >> a[i] >> b[i] >> c[i];
	}
	for (int i = 0; i < MAX_C;i++) {
		for (int j = 0; j < Min;j++) {
			dp[i][j] = -INF;
		}
	}

	dp[0][0] = 0;
	for (int i = 0; i < N;i++) {
		for (int j = MAX_C - 1; j >= 0; j--) {
			for (int k = Min - 1; k >= 0;k--) {
				if (dp[j][k] == -INF)continue;
				if (j + c[i] > C)continue;
				ll x = min(k + a[i], dp[j][k] + b[i]);
				ll y = max(k + a[i], dp[j][k] + b[i]);
				dp[j + c[i]][x] = max(dp[j + c[i]][x], y);

				x = min(k + b[i], dp[j][k] + a[i]);
				y = max(k + b[i], dp[j][k] + a[i]);
				dp[j + c[i]][x] = max(dp[j + c[i]][x], y);
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < MAX_C;i++) {
		for (int j = Min - 1; j >= 0;j--) {
			if (dp[i][j] == -INF) continue;
			ans = max(ans, (ll)j);
			break;
		}
	}
	cout << ans << endl;
	return 0;
}