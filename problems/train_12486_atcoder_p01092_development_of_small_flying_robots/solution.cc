#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;

template <class T>
pair<vector<T>, map<T, int> > compress(vector<T>& a) {
	vector<T> v;
	for(int i = 0; i < a.size(); i++) v.push_back(a[i]);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	map<T, int> m;
	for(int i = 0; i < v.size(); i++) m[v[i]] = i;
	return { v, m };
}

struct edge {
	int x, y, z;
	int cost;
};

struct S {
	int x, y, z;
	int cost;

	bool operator <(const S& x) const{
		return cost > x.cost;
	}
};

using P = pair<int, int>;
vector<edge> G[300][300][11];
int dist[300][300][11];
int sum[300][300];

int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, M, K, R;
	vector<int> X(100), Y(100), Z(100), xl(50), xr(50), yt(50), yb(50), h(50);
	while(cin >> N, N) {
		cin >> M >> K >> R;

		vector<int> xs, ys;
		for(int i = 0; i < N; i++) {
			cin >> X[i] >> Y[i] >> Z[i];
			xs.push_back(X[i]);
			ys.push_back(Y[i]);
		}
		for(int i = 0; i < M; i++) {
			cin >> xl[i] >> yt[i] >> xr[i] >> yb[i] >> h[i];
			xs.push_back(xl[i]);
			xs.push_back(xr[i]);
			ys.push_back(yt[i]);
			ys.push_back(yb[i]);
			if(h[i] == K) {
				if(xl[i] - 1 >= 1) xs.push_back(xl[i] - 1);
				if(xr[i] + 1 <= R) xs.push_back(xr[i] + 1);
				if(yt[i] - 1 >= 1) ys.push_back(yt[i] - 1);
				if(yb[i] + 1 <= R) ys.push_back(yb[i] + 1);
			}
		}

		auto zipX = compress(xs);
		auto zipY = compress(ys);

		int XN = zipX.first.size();
		int YN = zipY.first.size();

		for(int k = 1; k <= K; k++) {
			for(int i = 0; i < XN; i++) {
				for(int j = 0; j < YN; j++) {
					G[i][j][k].clear();
				}
			}
		}

		for(int k = 1; k <= K; k++) {
			for(int i = 0; i < XN; i++) {
				for(int j = 0; j < YN; j++) {
					int cx = zipX.first[i];
					int cy = zipY.first[j];
					if(k == K) {
						for(int l = 0; l < 4; l++) {
							if(i + dx[l] < 0 || XN <= i + dx[l]) continue;
							if(j + dy[l] < 0 || YN <= j + dy[l]) continue;
							int nx = zipX.first[i + dx[l]];
							int ny = zipY.first[j + dy[l]];
							int cost = abs(cx - nx) + abs(cy - ny);
							G[i][j][k].push_back({ i + dx[l], j + dy[l], k, cost });
						}
					}
					else {
						for(int m = 0; m < M; m++) {
							if(k + 1 != h[m]) continue;
							int cost = INF;
							int ii = 0, jj = 0;
							int li = zipX.second[xl[m]];
							int ri = zipX.second[xr[m]];
							int tj = zipY.second[yt[m]];
							int bj = zipY.second[yb[m]];
							if(li <= i && i <= ri && tj <= j && j <= bj) {
								if(cost > 100) {
									cost = 100;
									ii = i, jj = j;
								}
							}
							else if(li <= i && i <= ri) {
								if(cost > 100 + abs(cy - yt[m])){
									cost = 100 + abs(cy - yt[m]);
									ii = i, jj = tj;
								}
								if(cost > 100 + abs(cy - yb[m])) {
									cost = 100 + abs(cy - yb[m]);
									ii = i, jj = bj;
								}
							}
							else if(tj <= j && j <= bj) {
								if(cost > 100 + abs(cx - xl[m])){
									cost = 100 + abs(cx - xl[m]);
									ii = li, jj = j;
								}
								if(cost > 100 + abs(cx - xr[m])) {
									cost = 100 + abs(cx - xr[m]);
									ii = ri, jj = j;
								}
							}
							else {
								if(cost > 100 + abs(cx - xl[m]) + abs(cy - yt[m])){
									cost = 100 + abs(cx - xl[m]) + abs(cy - yt[m]);
									ii = li, jj = tj;
								}
								if(cost > 100 + abs(cx - xr[m]) + abs(cy - yt[m])){
									cost = 100 + abs(cx - xr[m]) + abs(cy - yt[m]);
									ii = ri, jj = tj;
								}
								if(cost > 100 + abs(cx - xl[m]) + abs(cy - yb[m])){
									cost = 100 + abs(cx - xl[m]) + abs(cy - yb[m]);
									ii = li, jj = bj;
								}
								if(cost > 100 + abs(cx - xr[m]) + abs(cy - yb[m])){
									cost = 100 + abs(cx - xr[m]) + abs(cy - yb[m]);
									ii = ri, jj = bj;
								}
							}
							G[i][j][k].push_back({ ii, jj, k + 1, cost });
						}
					}
				}
			}
		}

		vector<P> goal;
		for(int i = 0; i < XN; i++) {
			for(int j = 0; j < YN; j++) {
				int cx = zipX.first[i];
				int cy = zipY.first[j];
				bool ok = true;
				for(int m = 0; m < M; m++) {
					if(K == h[m] && xl[m] <= cx && cx <= xr[m] && yt[m] <= cy && cy <= yb[m]) {
						ok = false;
						break;
					}
				}
				if(ok) goal.push_back({ i, j });
			}
		}

		memset(sum, 0, sizeof sum);
		for(int n = 0; n < N; n++) {
			fill((int*)begin(dist), (int*)end(dist), INF);
			dist[zipX.second[X[n]]][zipY.second[Y[n]]][Z[n]] = 0;
			priority_queue<S> q;
			q.push({ zipX.second[X[n]],zipY.second[Y[n]], Z[n], 0 });
			while(q.size()) {
				S s = q.top();
				q.pop();
				if(dist[s.x][s.y][s.z] < s.cost) continue;
				for(auto& e : G[s.x][s.y][s.z]) {
					int ncost = s.cost + e.cost;
					if(dist[e.x][e.y][e.z] > ncost){
						dist[e.x][e.y][e.z] = ncost;
						q.push({ e.x, e.y, e.z, ncost });
					}
				}
			}
			for(auto& g : goal) {
				sum[g.first][g.second] += dist[g.first][g.second][K];
			}
		}
		int ans = INF;
		for(auto& g : goal) {
			ans = min(ans, sum[g.first][g.second]);
		}
		cout << ans << endl;
	}
}