#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int non = 10000000;

struct edge {
	int x, y, f, c, r;
};
vector<edge> E[202];

void add(int x, int y, int f, int c) {
	int p = E[x].size(), q = E[y].size();
	E[x].push_back({ x, y, f, c, q });
	E[y].push_back({ y, x, 0, -c, p });
}

int N, M, P, s, t;
vector<int> last_dist;

int spfa(){
	vector<int> dist(N, non), viax(N), viap(N);
	vector<bool> chk(N);
	priority_queue<pair<int, int> > qu;
	qu.push({ 0, s }); dist[s] = 0;
	while (!qu.empty()) {
		int c = -qu.top().first, x = qu.top().second; qu.pop();
		if (dist[x] < c) continue;
		int p = 0;
		for (auto &e : E[x]) {
			if (e.f) {
				int y = e.y, nc = c + e.c + last_dist[y] - last_dist[x];
				if (dist[y] > nc) {
					qu.push({ -nc, y });
					dist[y] = nc;
					viax[y] = x;
					viap[y] = p;
				}
			}
			p++;
		}
	}

	if (dist[t] == non) return 0;
	int ret = dist[t] - last_dist[t] + last_dist[s];
	last_dist = dist;
	int y = t;
	while (y != s) {
		int x = viax[y];
		auto &e = E[x][viap[y]];
		e.f--;
		E[y][e.r].f++;
		y = x;
	}
	return ret;
}

int main(){
	scanf("%d %d %d %d %d", &N, &M, &P, &s, &t);
	s--; t--;

	for (int i = 0; i < M; i++) {
		int x, y, d, c;
		scanf("%d %d %d %d", &x, &y, &d, &c); x--; y--;
		add(x, y, c, d);
	}

	int sum = 0, flow = 0; double ans = 1e10;
	last_dist = vector<int>(N, non);
	while (1) {
		int now = spfa();
		if (now == 0) break;
		sum += now; flow++;
		ans = min(ans, 1. * (sum + P) / flow);
	}
	printf("%.12lf\n", ans);
}

