#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

UL N, Q;
UL P[100000][18];
UL D[100000];
UL C[100000];
vector<pair<UL, UL>> E[100000];

UL LCA(UL a, UL b) {
	if (C[a] < C[b]) swap(a, b);
	UL d = C[a] - C[b];
	for (UL i = 17; i != ~0u; i--) {
		if ((1u << i) & d) a = P[a][i];
	}
	if (a == b) return a;
	for (UL i = 17; i != ~0u; i--) {
		if (P[a][i] == P[b][i]) continue;
		a = P[a][i]; b = P[b][i];
	}
	return P[a][0];
}

pair<UL, UL> MP(UL a, UL b) {
	UL X = D[LCA(a, b)];
	if (D[a] < D[b]) swap(a, b);
	UL Y = D[a] - D[b] + X + X;
	for (UL i = 17; i != ~0u; i--) {
		if (D[P[a][i]] * 2 <= Y) continue;
		a = P[a][i];
	}
	if (X == D[a]) return{ a,a };
	else return { a, P[a][0] };
}

UL Dist(UL a, UL b) {
	UL X = D[LCA(a, b)];
	return D[a] + D[b] - X - X;
}

int main() {
	scanf("%u%u", &N, &Q);
	rep(i, N - 1) {
		UL u, v, w; scanf("%u%u%u", &u, &v, &w); u--; v--;
		E[u].push_back({ v, w });
		E[v].push_back({ u, w });
	}
	{
		P[0][0] = 0; D[0] = 0; C[0] = 0;
		queue<UL> G; G.push(0);
		while (G.size()) {
			UL p = G.front(); G.pop();
			for (auto& e : E[p]) {
				if (P[p][0] == e.first) continue;
				P[e.first][0] = p;
				D[e.first] = D[p] + e.second;
				C[e.first] = C[p] + 1;
				G.push(e.first);
			}
		}
	}
	rep(i, 17) rep(j, N) P[j][i + 1] = P[P[j][i]][i];

	rep(q, Q) {
		UL a, b, c; scanf("%u%u%u", &a, &b, &c); a--; b--; c--;
		UL ans = ~0u;
		rep(t, 3) {
			auto mp = MP(a, b);
			UL q1 = max(max(Dist(mp.first, a), Dist(mp.first, b)), Dist(mp.first, c));
			UL q2 = max(max(Dist(mp.second, a), Dist(mp.second, b)), Dist(mp.second, c));
			ans = min(ans, min(q1, q2));
			swap(a, b); swap(b, c);
		}
		printf("%u\n", ans);
	}
	return 0;
}

