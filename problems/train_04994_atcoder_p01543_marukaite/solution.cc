#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (int (i) = (int)(n) - 1 ; (i) >= m ; --(i))
#define ALL(x) x.begin(), x.end()

//#define INF (1e10)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
template<class T> void print(const T& x) { cout << setprecision(16) << x << endl; }
template<class T, class... A> void print(const T& first, const A& ... rest) { cout << first << " "; print(rest...); }
struct PreMain { PreMain() { cin.tie(0); ios::sync_with_stdio(false); } } premain;


#define N_MAX	(100)


typedef int FLOW;                // フローを表す型、今回は int 型
typedef int COST;                // コストを表す型、今回は int 型
const int MAX_V = N_MAX*2 + 2;           // グラフの最大ノード数
const COST INF = 100000000;      // 十分大きい値

// グラフの辺の構造体
struct Edge {
	int rev, from, to;
	FLOW cap, icap;
	COST cost;
	Edge(int r, int f, int t, FLOW ca, COST co) : rev(r), from(f), to(t), cap(ca), icap(ca), cost(co) {}
};

// グラフ構造体
struct Graph {
	int V;
	vector<Edge> list[MAX_V];

	Graph(int n = 0) : V(n) { for (int i = 0; i < MAX_V; ++i) list[i].clear(); }
	void init(int n = 0) { V = n; for (int i = 0; i < MAX_V; ++i) list[i].clear(); }
	void resize(int n = 0) { V = n; }
	void reset() { for (int i = 0; i < V; ++i) for (int j = 0; j < list[i].size(); ++j) list[i][j].cap = list[i][j].icap; }
	inline vector<Edge>& operator [] (int i) { return list[i]; }

	Edge& redge(Edge& e) {
		if (e.from != e.to) return list[e.to][e.rev];
		else return list[e.to][e.rev + 1];
	}

	void addedge(int from, int to, FLOW cap, COST cost) {
		list[from].push_back(Edge((int)list[to].size(), from, to, cap, cost));
		list[to].push_back(Edge((int)list[from].size() - 1, to, from, 0, -cost));
	}
};

// 最小費用流を求める関数
COST MinCostFlow(Graph& G, int s, int t, FLOW inif) {
	COST dist[MAX_V];
	int prevv[MAX_V] = { 0 };
	int preve[MAX_V] = { 0 };

	COST res = 0;
	FLOW f = inif;
	while (f > 0) {
		fill(dist, dist + G.V, INF);
		dist[s] = 0;
		while (true) {
			bool update = false;
			for (int v = 0; v < G.V; ++v) {
				if (dist[v] == INF) continue;
				for (int i = 0; i < G[v].size(); ++i) {
					Edge& e = G[v][i];
					if (e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
						dist[e.to] = dist[v] + e.cost;
						prevv[e.to] = v;
						preve[e.to] = i;
						update = true;
					}
				}
			}
			if (!update) break;
		}

		if (dist[t] == INF) return 0;

		FLOW d = f;
		for (int v = t; v != s; v = prevv[v]) {
			d = min(d, G[prevv[v]][preve[v]].cap);
		}
		f -= d;
		res += dist[t] * d;
		for (int v = t; v != s; v = prevv[v]) {
			Edge& e = G[prevv[v]][preve[v]];
			Edge& re = G.redge(e);
			e.cap -= d;
			re.cap += d;
		}
	}
	return res;
}



int main() {
	int N;
	cin >> N;

	int W[N_MAX][N_MAX];
	int E[N_MAX][N_MAX];
	REP(i, N) {
		REP(j, N) {
			cin >> W[i][j];
		}
	}
	REP(i, N) {
		REP(j, N) {
			cin >> E[i][j];
		}
	}

	string F[N_MAX];
	REP(i, N) {
		cin >> F[i];
	}

	int base = 0;
	Graph G(2 * N + 2);
	REP(i, N) {
		REP(j, N) {
			if (F[i][j] == 'o') {
				G.addedge(i, j+N, 1, -E[i][j]);
				base += E[i][j];
			}
			else {
				G.addedge(i, j+N, 1, W[i][j]);
			}
		}
	}

	int node_start = (2 * N), node_end = (2 * N + 1);
	REP(i, N) {
		G.addedge(node_start, i, 1, 0);
	}
	REP(j, N) {
		G.addedge(j+N, node_end, 1, 0);
	}

	auto minCost = MinCostFlow(G, node_start, node_end, N);
	print(base + minCost); 

	//capが0になったedgeかどうか
	vector<string> ans;
	bool is_zero[N_MAX][N_MAX];
	for (auto &edges : G.list) {
		for (auto& edge : edges) {
			if (((2 * N) <= edge.from) || ((2 * N) <= edge.to)) {
				continue;
			}
			int i = edge.from;
			if (N <= i) {
				//i -= N;
				continue;
			}
			int j = edge.to;
			if (N <= j) {
				j -= N;
			}
			else {
				continue;
			}
			if (edge.cap != edge.icap) {
				if (F[i][j] == '.') {
					ans.push_back(string(to_string(i + 1) + " " + to_string(j + 1) + " " + "write"));
				}
			}
			else {
				if (F[i][j] == 'o') {
					ans.push_back(string(to_string(i + 1) + " " + to_string(j + 1) + " " + "erase"));
				}
			}
		}
	}

	print(ans.size());
	for (auto& s : ans) {
		print(s);
	}

	return 0;
}

