//無心でDPします
#include <iostream>
#include <algorithm>
#include <cstdio>
#define rep(i, n) for (i = 0; i < n; i++)
#define repn(i, m, n) for (i = m; i < n; i++)
#define int long long
using namespace std;

int INF = 1e+12;
int n, m;
int a[500];
int ra[501];
double dp[501][501];	//dp[pos][cnt] = max

signed main() {
	int i, j, k;
	
	cin >> n >> m;
	rep(i, n) cin >> a[i];
	rep(i, n) ra[i + 1] = ra[i] + a[i];
	
	rep(i, n + 1) rep(j, m + 1) dp[i][j] = -INF;
	
	dp[0][0] = 0;
	rep(i, n) {
		rep(j, m) {
			repn(k, i + 1, n + 1) {
				double high = (ra[k] - ra[i]) / (double)(k - i);
				dp[k][j + 1] = max(dp[k][j + 1], dp[i][j] + high);
			}
		}
	}
	
	//rep(i, n + 1) { rep(j, m + 1) cout << dp[i][j] << " "; cout << endl; }
	printf("%.14f\n", dp[n][m]);
	return 0;
}
