#include <cstdio>
#include <vector>
#include <set>
using namespace std;
const int mod = 998244353;
set<int> e[510][510];
int a[1010][510], d[1010][1010], u[1010];
vector<int> col[2], g[1010];
void dfs(int v, int b) {
	u[v] = -2;
	col[b].push_back(v);
	for (int i = 0; i < g[v].size(); i++) {
		int w = g[v][i];
		if (u[w] == -1) dfs(w, !b);
	}
}
void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			e[i][j].clear();
		}
	}
	for (int i = 0; i < 2 * n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			d[i][j] = 0;
		}
	}
	for (int i = 0; i < 2 * n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
			--a[i][j];
			e[j][a[i][j]].insert(i);
		}
		u[i] = -1;
	}
	vector<int> ad;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (e[i][j].size() == 1) {
				int x = *e[i][j].begin();
				if (u[x] != 1) {
					ad.push_back(x);
					u[x] = 1;
				}
				e[i][j].clear();
			}
		}
	}
	while (ad.size()) {
		set<int> de;
		for (int i = 0; i < ad.size(); i++) {
			for (int j = 0; j < n; j++) {
				int x = a[ad[i]][j];
				e[j][x].erase(ad[i]);
				de.insert(e[j][x].begin(), e[j][x].end());
				e[j][x].clear();
			}
		}
		ad.clear();
		vector<int> v(de.begin(), de.end());
		for (int i = 0; i < v.size(); i++) {
			u[v[i]] = 0;
			for (int j = 0; j < n; j++) {
				int x = a[v[i]][j];
				e[j][x].erase(v[i]);
				if (e[j][x].size() == 1) {
					int y = *e[j][x].begin();
					if (u[y] != 1) {
						ad.push_back(y);
						u[y] = 1;
					}
					e[j][x].clear();
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vector<int> w(e[i][j].begin(), e[i][j].end());
			for (int k = 0; k < w.size(); k++) {
				for (int l = k + 1; l < w.size(); l++) {
					d[w[k]][w[l]] = d[w[l]][w[k]] = 1;
				}
			}
		}
	}
	for (int i = 0; i < 2 * n; i++) {
		g[i].clear();
		for (int j = 0; j < 2 * n; j++) {
			if (d[i][j]) g[i].push_back(j);
		}
	}
	int ans = 1;
	for (int i = 0; i < 2 * n; i++) {
		if (u[i] != -1) continue;
		col[0].clear();
		col[1].clear();
		dfs(i, 0);
		int t = col[0].size() < col[1].size();
		for (int k = 0; k < 2; k++) {
			for (int j = 0; j < col[k].size(); j++) {
				u[col[k][j]] = k == t;
			}
		}
		if (col[0].size() == col[1].size()) {
			ans += ans;
			if (ans >= mod) ans -= mod;
		}
	}
	printf("%d\n", ans);
	for (int i = 0; i < 2 * n; i++) {
		if (u[i]) printf("%d ", i + 1);
	}
	puts("");
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
