#include <iostream>
using namespace std;
const int lim = 50;
int n, a[55], b[55]; long long c[55]; bool dp[55][55][55];
int main() {
	for (int i = 0; i <= lim; i++) dp[0][i][i] = true;
	for (int i = 1; i <= lim; i++) {
		for (int j = 0; j <= lim; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j][k] = dp[i - 1][j][k] || dp[i - 1][j % i][k];
			}
		}
	}
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], c[i] = 1LL << a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	bool feasible = true;
	for (int i = 0; i < n; i++) feasible = feasible && dp[lim][a[i]][b[i]];
	if (!feasible) cout << "-1\n";
	else {
		long long ret = 0;
		for (int i = lim; i >= 1; i--) {
			bool change = false;
			for (int j = 0; j < n; j++) {
				bool unchange = false;
				for (int k = 0; k <= lim; k++) {
					if (dp[i - 1][k][b[j]] && ((c[j] >> k) & 1)) {
						unchange = true;
					}
				}
				if (!unchange) change = true;
			}
			if (change) {
				for (int j = 0; j < n; j++) {
					for (int k = i; k <= lim; k++) {
						if ((c[j] >> k) & 1) c[j] |= 1LL << (k % i);
					}
				}
				ret |= 1LL << i;
			}
		}
		cout << ret << "\n";
	}
	return 0;
}