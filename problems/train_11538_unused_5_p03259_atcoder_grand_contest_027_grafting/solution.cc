#include <bits/stdc++.h>
#define popc64 __builtin_popcountll
#define ctz64 __builtin_ctzll

typedef unsigned long long u64;
const int N = 54;

int n, que[N];
int p1[N], p2[N];
u64 G1[N], G2[N], tG[N], iG[N];
u64 tag, mask;

inline void down(int &x, const int y) {x > y ? x = y : 0;}

void dfs(int x, int *p, u64 *G) {
	int y; u64 S;
	for (S = G[x]; S; S &= S - 1) if ((y = ctz64(S)) != p[x]) p[y] = x, dfs(y, p, G);
}

void common_dfs(int x, int px = -1) {
	int y; u64 S, G = G1[x] & G2[x]; tag &= ~(1llu << x);
	for (S = G; S; S &= S - 1) if ((y = ctz64(S)) != px) common_dfs(y, x);
}

int solve(int root) {
	int i, v, h, t = 0; u64 S;
	p1[root] = p2[root] = -1, tag = mask;
	dfs(root, p1, G1), dfs(root, p2, G2), common_dfs(root);
	memset(tG, 0, sizeof tG), memset(iG, 0, sizeof iG);
	for (S = tag; S; S &= S - 1) {
		v = ctz64(S);
		if (~p1[v] && tag >> p1[v] & 1) tG[v] |= 1llu << p1[v], iG[ p1[v] ] |= 1llu << v;
		if (~p2[v] && tag >> p2[v] & 1) iG[v] |= 1llu << p2[v], tG[ p2[v] ] |= 1llu << v;
	}
	for (i = 0; i < n; ++i) if (!iG[i]) que[t++] = i;
	for (h = 0; h < t; ++h)
		for (S = tG[v = que[h]]; S; S &= S - 1)
			if (!(iG[i = ctz64(S)] &= ~(1llu << v))) que[t++] = i;
	return t == n ? popc64(tag) : INT_MAX;
}

void work() {
	int i, u, v, ans = INT_MAX;
	scanf("%d", &n), mask = ~(-1llu << n);
	memset(G1, 0, sizeof G1), memset(G2, 0, sizeof G2);
	for (i = 1; i < n; ++i) scanf("%d%d", &u, &v), G1[--u] |= 1llu << --v, G1[v] |= 1llu << u;
	for (i = 1; i < n; ++i) scanf("%d%d", &u, &v), G2[--u] |= 1llu << --v, G2[v] |= 1llu << u;
	if (!memcmp(G1, G2, n << 3)) {putchar(48), putchar(10); return;}
	for (u = 0; u < n; ++u)
		if (!((G1[u] - 1) & G1[u])) {
			v = ctz64(G1[u]), G1[u] = 0, G1[v] &= ~(1llu << u);
			for (i = 0; i < n; ++i) if (i != u && i != v)
				G1[u] = 1llu << i, G1[i] |= 1llu << u,
				down(ans, solve(u)), G1[i] &= ~(1llu << u);
			G1[u] = 1llu << v, G1[v] |= 1llu << u;
		}
	printf("%d\n", ans == INT_MAX ? -1 : ans + 1);
}

int main() {
	int T;
	for (scanf("%d", &T); T; --T) work();
	return 0;
}