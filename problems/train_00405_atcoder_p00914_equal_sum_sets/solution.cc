#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;

int dp[30][20][200];
int main() {
	int N, K, S;
	while (scanf("%d%d%d", &N, &K, &S), N) {
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i <= N; i++)dp[i][0][0] = 1;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= K; j++) {
				for (int k = 0; k <= S; k++) {
					if (k < i)dp[i][j][k] = dp[i - 1][j][k];
					else dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k - i];
				}
			}
		}
		printf("%d\n", dp[N][K][S]);
	}
}