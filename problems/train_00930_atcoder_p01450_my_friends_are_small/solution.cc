#include<iostream>
#include<algorithm>
using namespace std;

#define MOD 1000000007
#define MAX_N 210
#define MAX_W 10100
int dp[2][MAX_N][MAX_W];
int N, W, x[MAX_N];
int main() {
	cin >> N >> W;
	for (int i = 1; i <= N; i++) {
		cin >> x[i];
	}
	x[N + 1] = W + 1;
	sort(x + 1, x + N + 1);
	dp[1][1][0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			for (int k = 0; k <= W; k++) {
				dp[0][j][k] = dp[1][j][k];
				dp[1][j][k] = 0;
			}
		}
		int w = x[i];
		int y = 0, z = 0;
		for (int j = 1; j <= i; j++) {
			y = j; z = j;
			if (y == i) { y += 1; }
			for (int k = 0; k <= W; k++) {
				if (k + w <= W) {
					dp[1][y][k + w] += dp[0][j][k];
					dp[1][y][k + w] %= MOD;
				}
				dp[1][z][k] += dp[0][j][k];
				dp[1][z][k] %= MOD;
			}
		}
	}
	int res = 0, v = 0;
	for (int i = 1; i <= N + 1; i++) {
		v = max(0, W - x[i] + 1);
		for (int j = v; j <= W; j++) {
			res += dp[1][i][j];
			res %= MOD;
		}
	}
	cout << res << endl;
	return 0;
}