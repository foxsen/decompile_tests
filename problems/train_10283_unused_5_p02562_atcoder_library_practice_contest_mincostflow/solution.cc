//#pragma warning(disable:4996)
//#include <Windows.h>
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <random>
#include <functional>
#include <stack>
#include <iomanip>
#include <cassert>
//#include <boost/multiprecision/cpp_int.hpp>
#include <complex>
#include <cstdio>
#include <list>
#include <bitset>
//#include <stdio.h>

//< in.txt > out.txt
using namespace std;
//std::ios::sync_with_stdio(false);
//std::cin.tie(0);
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
typedef long long LL;
typedef long double LD;
//typedef boost::multiprecision::cpp_int bigint;
typedef pair<LL, LL> PLL;
typedef pair<int, int> PI;
typedef pair<LD, LL> pdl;
typedef pair<LD, LD> pdd;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef unsigned long long ULL;
template<class T>
using pqueue = priority_queue<T, vector<T>, function<bool(T, T)>>;

template<class T>
inline void chmin(T& a, T b) {
	a = min(a, b);
}

template<class T>
inline void chmax(T& a, T b) {
	a = max(a, b);
}

void input();
void solve();

void daminput();
void naive();

void outputinput();

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	input();
	//daminput();
	solve();
	//naive();
	//outputinput();
	return 0;
}

//////////////////////////////////////////////////
//////////////////////////////////////////////////

int N, K;
VVLL A;

void input() {
	cin >> N >> K;
	A.resize(N);
	for (int y = 0; y < N; y++) {
		A[y].resize(N);
		for (int x = 0; x < N; x++) {
			cin >> A[y][x];
		}
	}
}

void daminput() {
}

template<class F, class C>
class MinCFEdge {
public:
	int to;
	F cap;
	C cost;
	int rev;
	MinCFEdge(int _to, F _cap, C _cost, int _rev) :to(_to), cap(_cap), cost(_cost), rev(_rev) {}
};

template<class F, class C>
class PrimalDual {
public:
	int V;
	C INF = numeric_limits<F>::max();
	vector<vector<MinCFEdge<F, C>>> G;
	vector<C> potential, dist;
	VI prevv, preve;
	PrimalDual(int v) :V(v) {
		potential.resize(V, 0);
		dist.resize(V, 0);
		prevv.resize(V, -1);
		preve.resize(V, -1);
		G.resize(V);
	}
	void AddEdge(int from, int to, F cap, C cost) {
		G[from].push_back({ to, cap, cost, (int)G[to].size() });
		G[to].push_back({ from,0, -cost, (int)G[from].size() - 1 });
	}
	C min_cost_flow(int s, int t, F flow) {
		fill(potential.begin(), potential.end(), 0);
		typedef pair<C, int> P;
		C res = 0;
		while (flow > 0) {
			//dijkstra
			priority_queue<P, vector<P>, greater<P>> q;
			fill(dist.begin(), dist.end(), INF);
			dist[s] = 0;
			q.emplace(0, s);
			while (!q.empty()) {
				C cost = q.top().first;
				int cur = q.top().second;
				q.pop();
				if (dist[cur] < cost)continue;
				for (int i = 0; i < G[cur].size(); i++) {
					MinCFEdge<F, C>& e = G[cur][i];
					if (e.cap <= 0)continue;
					if (dist[e.to] <= dist[cur] + e.cost + potential[cur] - potential[e.to])continue;
					dist[e.to] = dist[cur] + e.cost + potential[cur] - potential[e.to];
					prevv[e.to] = cur;
					preve[e.to] = i;
					q.emplace(dist[e.to], e.to);
				}
			}
			if (dist[t] == INF)return -1;
			for (int v = 0; v < V; v++)potential[v] += dist[v];
			F f = flow;
			int v = t;
			while (v != s) {
				f = min(f, G[prevv[v]][preve[v]].cap);
				v = prevv[v];
			}
			flow -= f;
			res += potential[t] * f;
			v = t;
			while (v != s) {
				MinCFEdge<F, C>& e = G[prevv[v]][preve[v]];
				e.cap -= f;
				MinCFEdge<F, C>& rev = G[e.to][e.rev];
				rev.cap += f;
				v = prevv[v];
			}
		}
		return res;
	}
};

void solve() {
	PrimalDual<LL, LL> P(N * N + 2*N + 4);
	auto conv = [&](int y, int x) {
		return y * N + x;
	};
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			P.AddEdge(N * N + y, conv(y, x), 1, 0);
			P.AddEdge(conv(y, x), N * N + N + x, 1, (LL)1e9 - A[y][x]);
		}
	}
	for (int n = N * N; n < N * N + N; n++) {
		P.AddEdge(N * N + 2 * N, n, K, 0);
	}
	for (int n = N * N + N; n < N * N + 2 * N; n++) {
		P.AddEdge(n, N * N + 2 * N + 1, K, 0);
	}
	P.AddEdge(N * N + 2 * N, N * N + 2 * N + 1, N * N, (LL)1e9);
	P.AddEdge(N * N + 2 * N + 2, N * N + 2 * N, N * N, 0);
	P.AddEdge(N * N + 2 * N + 1, N * N + 2 * N + 3, N * N, 0);
	LL mincost = P.min_cost_flow(N * N + 2 * N + 2, N * N + 2 * N + 3, N * N);
	cout << (LL)1e9 * N * N - mincost << "\n";
	for (int y = 0; y < N; y++) {
		string S("");
		for (int x = 0; x < N; x++) {
			for (auto& edge : P.G[conv(y, x)]) {
				if (edge.to != N * N + N + x)continue;
				if (edge.cap == 0)S += string("X");
				else S += string(".");
			}
		}
		cout << S << "\n";
	}
}

void naive() {
}

void outputinput() {
}