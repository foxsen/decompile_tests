#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, int> city;

const int MAXN = 1e5 + 5;
const ll INF = 1e15;

int N, M, S, T;
vector <pii> E1[MAXN], E2[MAXN];
ll distS[MAXN], distT[MAXN];
ll ans[MAXN];

void load() {
	scanf("%d%d%d%d", &N, &M, &S, &T);
	while (M--) {
		int u, v, a, b;
		scanf("%d%d%d%d", &u, &v, &a, &b);
		E1[u].push_back({v, a});
		E1[v].push_back({u, a});
		E2[u].push_back({v, b});
		E2[v].push_back({u, b});
	}
}

void dijkstra(int src, ll dist[MAXN], vector <pii> E[MAXN]) {
	for (int i = 1; i <= N; i++)
		dist[i] = INF;
	dist[src] = 0;
	
	set <city> curr;
	for (int i = 1; i <= N; i++)
		curr.insert({dist[i], i});
	
	while (!curr.empty()) {
		int x = curr.begin() -> second;
		curr.erase(curr.begin());
		for (auto it : E[x]) {
			ll tmp = dist[x] + it.second;
			if (tmp < dist[it.first]) {
				curr.erase({dist[it.first], it.first});
				dist[it.first] = tmp;
				curr.insert({dist[it.first], it.first});
			}
		}
	}
}

void solve() {
	dijkstra(S, distS, E1);
	dijkstra(T, distT, E2);
		
	for (int i = N; i; i--) {
		ans[i] = distS[i] + distT[i];
		if (i < N)
			ans[i] = min(ans[i], ans[i + 1]);
	}
	
	for (int i = 1; i <= N; i++)
		printf("%lld\n", INF - ans[i]);
}

int main() {
	load();
	solve();
	return 0;
}