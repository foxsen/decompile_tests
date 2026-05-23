#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define INF 1<<30
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

vector<int> g[100005];

// cost, index
pair<int, int> dfs(int cur, int prev) {
	pair<int, int> ret(0, cur);
	rep(i, g[cur].size()) {
		int to = g[cur][i];
		if(to == prev) continue;
		pair<int, int> t = dfs(to, cur);
		t.first++;
		if(ret.first < t.first) ret = t;
	}
	return ret;
}

int root = 0;
int parent[20][100005];
int depth[100005];

void dfs2(int v, int p, int d) {
	parent[0][v] = p;
	depth[v] = d;
	rep(i, g[v].size()) {
		if(g[v][i] != p) dfs2(g[v][i], v, d+1);
	}
}

void init(int V) {
	dfs2(root, -1, 0);
	for(int k = 0; k + 1 < 20; k++) {
		rep(v, V) {
			if(parent[k][v] < 0) parent[k + 1][v] = -1;
			else parent[k + 1][v]= parent[k][parent[k][v]];
		}
	}
}

int lca(int u, int v) {
	if(depth[u] > depth[v]) swap(u, v);
	rep(k, 20) {
		if((depth[v] - depth[u]) >> k & 1) {
			v = parent[k][v];
		}
	}
	if(u == v) return u;
	for(int k = 20 - 1; k >= 0; k--) {
		if(parent[k][u] != parent[k][v]) {
			u = parent[k][u];
			v = parent[k][v];
		}
	}
	return parent[0][u];
}

int main() {
	int n;
	cin >> n;

	rep(i, n-1) {
		int a, b;
		cin >> a >> b;

		a--; b--;

		g[a].push_back(b);
		g[b].push_back(a);
	}

	// cout << "input" << endl;
	// rep(i, n) {
	// 	cout << " i : " << i << " | ";
	// 	rep(j, g[i].size()) cout << g[i][j] << " ";
	// 	cout << endl;
	// }


	P s = dfs(0, -1);
	P t = dfs(s.second, -1);
	// cout << s.second << " " << t.second << endl;

	init(n);

	rep(i, n) {
		int c = lca(i, s.second);
		int a = (depth[i] - depth[c]) + (depth[s.second] - depth[c]);

		int d = lca(i, t.second);
		int b = (depth[i] - depth[d]) + (depth[t.second] - depth[d]);

		cout << 2 * (n - 1) - max(a, b) << endl;
	}

	return 0;
}