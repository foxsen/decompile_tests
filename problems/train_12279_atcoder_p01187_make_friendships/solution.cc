#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct BipartiteMatching {
	int V;
	vector<vector<bool> > G;
	vector<int> match;
	vector<bool> used;

	BipartiteMatching(int v) {
		V = v;
		G = vector<vector<bool> >(v, vector<bool>(v));
		match = vector<int>(v);
		used = vector<bool>(v);
	}

	void add_edge(int v, int u) {
		G[v][u] = G[u][v] = true;
	}

	bool dfs(int v) {
		used[v] = true;
		for(int i = 0; i < V; i++) {
			if(!G[v][i]) continue;
			int u = i, w = match[u];
			if(w < 0 || (!used[w] && dfs(w))) {
				match[v] = u;
				match[u] = v;
				return true;
			}
		}
		return false;
	}

	int calc() {
		int res = 0;
		fill(match.begin(), match.end(), -1);
		for(int v = 0; v < V; v++) {
			if(match[v] < 0) {
				fill(used.begin(), used.end(), false);
				if(dfs(v)) {
					res++;
				}
			}
		}
		return res;
	}
};


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	while(cin >> N, N) {
		int M;
		cin >> M;
		map<int, int> id;
		for(int i = 0; i < M; i++) {
			int a;
			cin >> a;
			id[a] = -1;
		}
		int cnt = 0;
		for(auto v : id) {
			id[v.first] = cnt++;
		}

		BipartiteMatching bm(cnt + N);
		for(int i = 0; i < N; i++) {
			cin >> M;
			for(int j = 0; j < M; j++) {
				int a;
				cin >> a;
				if(id.count(a) == 0) continue;
				bm.add_edge(id[a], cnt + i);
			}
		}

		cout << bm.calc() << endl;
	}

}