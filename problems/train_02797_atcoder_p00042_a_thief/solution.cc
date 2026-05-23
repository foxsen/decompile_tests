#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int dp[1001][1001] = {0};
int main() {
	int W, N;
	int t = 1;
	while ( cin >> W, W ) {
		cin >> N;
		vector<int> v(N), w(N);
		for (int i = 0; i < N; ++i) {
			scanf("%d,%d", &v[i], &w[i]);
		}
		fill(&dp[0][0], &dp[0][0]+1001*1001, 0);
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j <= W; ++j) {
				if (w[i] + j <= W) {
					dp[i+1][w[i] + j] = max(dp[i+1][w[i] + j], dp[i][j] + v[i]);
				}
				dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
			}
		}
		int aw = 0, av = 0;
		for (int i = 0; i <= W; ++i) {
			if (dp[N][i] > av) {
				av = dp[N][i], aw = i;
			}
		}
		cout << "Case " << t << ":" << endl;
		cout << av << endl;
		cout << aw << endl;
		++t;
	}
}