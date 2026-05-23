#include <stdio.h>
#include <iostream>
#include <vector>
#include <assert.h>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <memory.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
typedef long long ll;
int R, C;
ll mn[2];
ll val[200000];
bool vis[200000];
vector<vector<pair<int, int> > > g;
void NO() {
	puts("No");
	exit(0);
}
void DFS(int u, ll should) {
	if (vis[u]) {
		if (should != val[u])
			NO();
		return;
	}
	val[u] = should;
	vis[u] = true;
	mn[u >= R] = min(mn[u >= R], val[u]);
	for (int i = 0; i < g[u].size(); ++i)
		DFS(g[u][i].first, g[u][i].second - val[u]);
}
int main()
{
	int n;
	scanf("%d%d%d", &R, &C, &n);
	g.resize(R + C);
	for (int r, c, k, i = 0; i < n; ++i) {
		scanf("%d%d%d", &r, &c, &k);
		--r; --c;
		g[r].push_back(make_pair(R + c, k));
		g[R + c].push_back(make_pair(r, k));
	}
	for(int i=0;i<g.size();++i)
		if (!vis[i]) {
			mn[0] = mn[1] = 1e18;
			DFS(i, 0);
			if (mn[0] + mn[1] < 0)
				NO();
		}
	puts("Yes");
	return 0;
}