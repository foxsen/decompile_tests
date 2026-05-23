#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cassert>
using namespace std;

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

	int N, M;
	while(cin >> N >> M) {
		BipartiteMatching bm(N + M);
		for(int i = 0; i < N; i++) {
			int K, b;
			cin >> K;
			for(int j = 0; j < K; j++) {
				cin >> b;
				b = b - 1 + N;
				bm.add_edge(i, b);
			}
		}

		if(bm.calc() == M) {
			cout << "Bob" << endl;
		}
		else {
			cout << "Alice" << endl;
		}
	}
}