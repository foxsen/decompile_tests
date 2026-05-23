#include "bits/stdc++.h"
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2151&lang=jp
using namespace std;
typedef long long ll;
#define INF 1<<30
#define LINF 1LL<<62

struct edge {
	int from, to;
	int dist, cost;
	edge() {}
	edge(int from, int to, int dist, int cost) :from(from), to(to), dist(dist), cost(cost) {}
};

int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	ll N, M, L;
	while (cin >> N >> M >> L, N | M | L) {
		vector<vector<edge>> G(N);
		for (int i = 0; i < M;i++) {
			ll A, B, D, E; cin >> A >> B >> D >> E;
			A--; B--;
			G[A].push_back(edge(A, B, D, E));
			G[B].push_back(edge(B, A, D, E));
		}

		/*                         hotel          balance */
		vector<vector<ll>> Assasin(N, vector<ll>(L + 1, INF));
		/*             hotel, balance*/
		using Key = tuple<ll, ll>;
		queue<Key> q;
		q.push(Key(0, L));
		Assasin[0][L] = 0;
		while (!q.empty()) {
			ll hotel, balance;
			tie(hotel, balance) = q.front(); q.pop();
			//cout << hotel << " " << balance << endl;
			for (auto e : G[hotel]) {
				if (e.dist <= balance) {
					if (Assasin[e.to][balance - e.dist] > Assasin[hotel][balance]) {
						Assasin[e.to][balance - e.dist] = Assasin[hotel][balance];
						q.push(Key(e.to, balance - e.dist));
					}
				}
				if (Assasin[e.to][balance] > Assasin[hotel][balance] + e.cost) {
					Assasin[e.to][balance] = Assasin[hotel][balance] + e.cost;
					q.push(Key(e.to, balance));
				}
			}
		}
		ll Ans = INF;
		for (int i = 0; i <= L;i++) {
			Ans = min(Ans, Assasin[N - 1][i]);
		}
		cout << Ans << endl;
	}
}