#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
using P = pair<int, int>;
using PP = pair<int, P>;

int N, M;
struct edge {
	P to;
	int cost;
};

template <typename T1, typename T2, typename T3>
int bfs(T1& G, T2& d, T3& used, P s) {
	deque<PP> deq;
	deq.push_back(PP(0, s));

	while (!deq.empty()) {
		PP q = deq.front();
		deq.pop_front();
		int cost = q.first;
		P v = q.second;
		if (used[v]) { continue; }
		used[v] = true;
		if (v == P(N - 1, -1)) { return cost; }

		for (int i = 0; i < G[v].size(); ++i) {
			if (used[G[v][i].to]) { continue; }
			if (G[v][i].cost == 0) {
				deq.push_front(PP(cost, G[v][i].to));
			} else {
				deq.push_back(PP(cost + 1, G[v][i].to));
			}
		}
	}
	return -1;
}

int main() {
	const int INF = 1e9;
	cin >> N >> M;
	map<P, vector<edge>> G;
	for (int i = 0; i < M; ++i) {
		int p, q, c;
		cin >> p >> q >> c;
		--p; --q;

		G[P(p, c)].push_back({P(q, c), 0});
		G[P(p, c)].push_back({P(p, -1), 0});
		G[P(p, -1)].push_back({P(q, c), 1});
		G[P(q, c)].push_back({P(p, c), 0});
		G[P(q, c)].push_back({P(q, -1), 0});
		G[P(q, -1)].push_back({P(p, c), 1});
	}

	map<P, int> d;
	map<P, bool> used;
	for (auto it = G.begin(); it != G.end(); ++it) {
		d[it->first] = INF;
		used[it->first] = false;
	}

	int res = bfs(G, d, used, P(0, -1));
	cout << res << endl;

	return 0;
}
