#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;

vector<int>E[100];
bool used[200];
int match[200];

bool dfs(int u) {
	used[u] = true;
	for (int v : E[u]) {
		int w = match[v];
		if (w == -1 || (!used[w] && dfs(w))) {
			match[u] = v; match[v] = u;
			return true;
		}
	}
	return false;
}
int x[100], y[100], z[100], a[100], b[100];
double d[100][100];
int main() {
	int n, m;
	while (scanf("%d%d", &n, &m), n) {
		rep(i, n)scanf("%d%d%d", &x[i], &y[i], &z[i]);
		rep(i, m)scanf("%d%d", &a[i], &b[i]);
		rep(i, n)rep(j, m)d[i][j] = hypot(x[i] - a[j], y[i] - b[j]) / z[i];
		double l = 0, r = 15000;
		rep(i, 45) {
			double t = (l + r) / 2;
			rep(j, n) {
				E[j].clear();
				rep(k, m) {
					if (d[j][k] <= t)E[j].push_back(n + k);
				}
			}
			int cnt = 0;
			memset(match, -1, sizeof(match));
			rep(j, n) {
				if (match[j] == -1) {
					memset(used, 0, sizeof(used));
					cnt += dfs(j);
				}
			}
			if (cnt == m)r = t;
			else l = t;
		}
		printf("%.14lf\n", l);
	}
}