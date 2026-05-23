#include <bits/stdc++.h>
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
int n, a[4010], b[4010], sum[2][4010][2010];
int pos[2][2010];
int dp[2010][2010];
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n+n; i++) {
		char ch;
		scanf(" %c %d", &ch, a+i);
		b[i] = ch == 'B';
		pos[b[i]][a[i]] = i;
		for(int j=a[i]; j<=n; j++)
			sum[b[i]][i][j]++;
	}
	for(int k=0; k<2; k++)
		for(int i=1; i<=n+n; i++)
			for(int j=1; j<=n; j++)
				sum[k][i][j] += sum[k][i-1][j];
	for(int i=0; i<=n; i++) {
		for(int j=0; j<=n; j++) {
			int p1 = pos[0][i];
			int p2 = pos[1][j];
			if(!i && !j) continue;
			else if(!i) {
				dp[i][j] = dp[i][j-1] + p2 - 1 - sum[1][p2][j-1] - sum[0][p2][i];
			} else if(!j) {
				dp[i][j] = dp[i-1][j] + p1 - 1 - sum[0][p1][i-1] - sum[1][p1][j];
			} else {
				dp[i][j] = min(dp[i-1][j] + p1 - 1 - sum[0][p1][i-1] - sum[1][p1][j], dp[i][j-1] + p2 - 1 - sum[1][p2][j-1] - sum[0][p2][i]);
			}
		}
	}
	printf("%d", dp[n][n]);
	return 0;
}