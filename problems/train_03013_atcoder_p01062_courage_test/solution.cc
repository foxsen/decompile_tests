#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> i_i;

int N;
i_i pp;

void dfs(int u, int p, vector<vector<int> >& G, vector<int>& num) {
	num[u] = 1;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (v == p) continue;
		dfs(v, u, G, num);
		num[u] += num[v];
		if (num[v] == N / 2)
			pp = i_i(u, v);
	}
}

struct union_find {
	vector<int> v;
	union_find(int n) : v(n, -1) {}
	int find(int x) { return (v[x] < 0) ? x : (v[x] = find(v[x])); }
	void unite(int x, int y) {
		x = find(x); y = find(y);
		if (x != y) {
			if (-v[x] < -v[y]) swap(x, y);
			v[x] += v[y]; v[y] = x;
		}
	}
	bool same(int x, int y) { return find(x) == find(y); }
	int size(int x) { return -v[find(x)]; }
};

int main() {
	int x, y; cin >> N >> x >> y;
	x--; y--;
	if (N == 2) {
		cout << "Yes" << endl;
		return 0;
	}
	if (N % 2 == 1) {
		cout << "No" << endl;
		return 0;
	}
	vector<vector<int> > G(N);
	vector<int> d(N), A, B;
	for (int i = 0; i < N - 1; i++) {
		int a, b; scanf("%d%d", &a, &b);
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
		d[a]++; d[b]++;
		A.push_back(a);
		B.push_back(b);
	}
	vector<int> num(N);
	dfs(0, -1, G, num);
	union_find uf(N);
	for (int i = 0; i < N - 1; i++) {
		int a = A[i], b = B[i];
		if (i_i(a, b) == pp || i_i(b, a) == pp) {
			d[a]--; d[b]--;
		}
		else uf.unite(a, b);
	}
	for (int u = 0; u < N; u++)
		if (d[u] >= 3) {
			cout << "No" << endl;
			return 0;
		}
	if (uf.same(x, y)) {
		cout << "No" << endl;
		return 0;
	}
	if (d[x] == 1 && d[y] == 1) {
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl;
}