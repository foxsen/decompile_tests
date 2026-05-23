#include <iostream>
#include <string>
using namespace std;

string S; int dp[300009][4][3], mod = 1000000007;

int main() {
	cin >> S;
	dp[0][0][0] = 1;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '0' || S[i] == '?') {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 3; k++) {
					if (dp[i][j][k] == 0) continue;
					int s = k + 1; if (s == 3) s = 1;
					dp[i + 1][j][s] += dp[i][j][k];
					dp[i + 1][j][s] %= mod;
				}
			}
		}
		if (S[i] == '1' || S[i] == '?') {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 3; k++) {
					if (dp[i][j][k] == 0) continue;
					int s = k - 1, t = j; if (s == -1) { s = 0; t++; if (t >= 4) t = 3; }
					dp[i + 1][t][s] += dp[i][j][k];
					dp[i + 1][t][s] %= mod;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			if (i - j >= 1) { ans += dp[S.size()][i][j]; ans %= mod; }
		}
	}
	cout << ans << endl;
	return 0;
}