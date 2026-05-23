#include<bits/stdc++.h>
using namespace std;

const int N = 105;
const int MOD = 1000000007;

int c[N], b[N];
int bs[N], bp[N];
int dp[N][N * N];

int n, q;
int rlt[N];

int main() {
	
	cin >> n;
	int M = 0, res = 1;
	for (int i = 1; i <= n; i ++) {
		cin >> c[i];
		if (c[i] > M) M = c[i];
		res = 1LL * res * (c[i] + 1) % MOD;
	}
	for (int i = 2; i <= n; i ++) {
		cin >> b[i];
		bs[i] = bs[i - 1] + b[i];
	}
	for (int i = 2; i <= n; i ++) bp[i] = bp[i - 1] + bs[i];
	int LX = -bp[n] / n, RX = LX + M + 1;
	for (int x = LX; x <= RX; x ++) {
		for (int i = 0; i <= n; i ++) for (int j = 0; j <= M * n; j ++) dp[i][j] = 0;
		dp[0][0] = 1;
		for (int i = 1; i <= n; i ++) {
			int L = i * x + bp[i], sum = 0;
			for (int j = 0; j <= n * M; j ++) {
				if (j >= 1) dp[i][j] = dp[i][j - 1];
				(dp[i][j] += dp[i - 1][j]) %= MOD;
				if (j > c[i]) (dp[i][j] += MOD - dp[i - 1][j - c[i] - 1]) %= MOD;
			}
			for (int j = 0; j < L; j ++) dp[i][j] = 0;
		}
		rlt[x - LX] = 0;
		for (int i = 0; i <= n * M; i ++) (rlt[x - LX] += dp[n][i]) %= MOD;
	}
	cin >> q;
	while (q --) {
		int x; cin >> x;
		if (x < LX) cout << res << endl;
		else if (x > RX) cout << 0 << endl;
		else cout << rlt[x - LX] << endl;
	}
}
