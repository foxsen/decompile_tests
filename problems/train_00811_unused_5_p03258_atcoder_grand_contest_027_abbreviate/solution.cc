#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int P = 1e9 + 7;
typedef long long ll;
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
char s[MAXN];
int dp[MAXN], pre[MAXN], lst[MAXN][3], trans[MAXN][3];
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
int main() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	memset(lst[0], -1, sizeof(lst[0]));
	for (int i = 1; i <= n; i++) {
		if (s[i] == 'a') pre[i] = (pre[i - 1] + 1) % 3;
		else pre[i] = (pre[i - 1] + 2) % 3;
		memcpy(lst[i], lst[i - 1], sizeof(lst[i - 1]));
		lst[i][pre[i - 1]] = i - 1;
	}
	memset(trans[0], -1, sizeof(trans[0]));
	for (int i = 1; i <= n; i++) {
		if (i != 1 && s[i - 1] == s[i]) memcpy(trans[i], lst[i], sizeof(lst[i]));
		else memcpy(trans[i], trans[i - 1], sizeof(trans[i - 1]));
	}
	if (trans[n][0] == -1) {
		cout << 1 << endl;
		return 0;
	}
	dp[n] = 1;
	for (int i = n; i >= 1; i--) {
		update(dp[i - 1], dp[i]);
		if (s[i] == 'a') {
			if (trans[i][(pre[i] + 1) % 3] != -1) update(dp[trans[i][(pre[i] + 1) % 3]], dp[i]);
		} else {
			if (trans[i][(pre[i] + 2) % 3] != -1) update(dp[trans[i][(pre[i] + 2) % 3]], dp[i]);
		}
	}
	int ans = 0;
	for (int i = 0; i <= n - 1; i++)
		if (pre[i] == 0) ans = (ans + dp[i]) % P;
	cout << ans << endl;
	return 0;
}