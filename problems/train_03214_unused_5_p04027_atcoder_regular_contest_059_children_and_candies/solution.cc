#include <bits/stdc++.h>

using namespace std;

const int N = (int)400 + 7;
const int mod = (int)1e9 + 7;

int add(int a, int b) {
	a += b;
	if (a > mod) a -= mod;
	return a;
}

int mul(int a, int b) {
	return (a * 1LL * b) % mod;
}

int n, c;
int a[N], b[N];
int sum[N][N];
int s[N][N];
int dp[N][N];

int main() {
	scanf("%d %d", &n, &c);
	for (int i = 0; i < n; i++) 
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) 
		scanf("%d", &b[i]);
	for (int i = 1; i < N; i++) {
		sum[i][0] = 1;
		for (int j = 1; j < N; j++) {
			sum[i][j] = mul(sum[i][j - 1], i);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = a[i]; j <= b[i]; j++) {
			for (int k = 0; k <= c; k++) {
				s[i][k] = add(s[i][k], sum[j][k]);
			}
		}
	}
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= c; j++) {
			if (!dp[i][j]) continue;
			for (int k = 0; k + j <= c; k++) {
				dp[i + 1][k + j] = add(dp[i + 1][k + j], mul(dp[i][j], s[i][k]));
			}
		}
	}
	printf("%d\n", dp[n][c]);
}
