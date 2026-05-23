#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define FF first
#define SS second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pie;
const int MOD = 1e9 + 7;
const int INF = 2e9;
const ll LINF = 4e18;
const ll delta = 96181;

const int N = 1e5 + 20;
vector<int> G[N];
int n, dp[N];

void dfs(int v, int p = -1) {
	int mx = 0, cnt = 0;
	for (int u : G[v])
		if (u - p) {
			dfs(u, v);
			if (dp[u])
				cnt++;
			dp[v] += dp[u];
		}
	if (p + 1)
		dp[v] += max(0, (int)G[v].size() - 2 - cnt);
	else
		dp[v] += max(0, (int)G[v].size() - 1 - cnt);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0, v, u; i < n - 1; i++) {
		cin >> v >> u;
		G[v].push_back(u);
		G[u].push_back(v);
	}
	int root = -1;
	for (int i = 0; i < n; i++)
		if (G[i].size() > 2)
			root = i;
	if (root == -1)
		return cout << 1 << endl, 0;
	dfs(root);
	cout << dp[root] << endl;
}

