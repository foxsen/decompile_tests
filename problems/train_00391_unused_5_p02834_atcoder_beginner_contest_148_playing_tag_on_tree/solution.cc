#include <bits/stdc++.h>

using namespace std;

int n, u, v;
int dist[2][100000];
vector<vector<int> > g;

void dfs(int v, int prev, int d, int f) {
	dist[f][v] = d;
	for (auto e : g[v])
		if (e != prev) dfs(e, v, d + 1, f);
}

int main() {
	cin >> n >> u >> v;
	--u, --v;
	g.resize(n);
	for (int i = 1; i < n; ++i) {
		int a, b; cin >> a >> b;
		--a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(u, -1, 0, 0);
	dfs(v, -1, 0, 1);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (dist[0][i] < dist[1][i]) {
			ans = max(ans, dist[1][i] - 1);
		}
	}
	cout << ans << endl;
	
	return 0;
}
