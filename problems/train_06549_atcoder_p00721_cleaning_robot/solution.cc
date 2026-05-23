#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

#define int long long

using namespace std;

class Solver {
};
signed main() {
	while (true) {
		int w, h;
		cin >> w >> h;
		if (w == 0)break;

		tuple<int, int> start;
		vector<vector<bool>> grid(h, vector<bool>(w, true));
		map<tuple<int,int>,int> points;
		int cnt = 0;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				char c;
				cin >> c;
				if (c == '.')continue;
				if (c == 'x') {
					grid[i][j] = false;
					continue;
				}
				if (c == 'o')start = make_tuple(i, j);
				if (c == '*') {
					cnt++;
					points.emplace(make_tuple(i, j), points.size() + 1);
				}
			}
		}
		points.emplace(start, 0);

		vector<map<int, int>> graph(points.size());
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (points.find(make_tuple(i, j)) == points.end())continue;

				int st_i = points[make_tuple(i, j)];

				vector<vector<int>> dist(h, vector<int>(w, 1e9));
				queue<tuple<int, int, int>> que;
				que.push(make_tuple(i, j, 0));
				while (que.size() > 0) {
					int y = get<0>(que.front());
					int x = get<1>(que.front());
					int d = get<2>(que.front());
					que.pop();
					if (dist[y][x] <= d)continue;

					dist[y][x] = d;
					if (points.find(make_tuple(y,x))!=points.end()
						&& (i != y || j != x)) {
						int index = points[make_tuple(y, x)];
						graph[st_i].emplace(index, d);
					}

					if (y > 0 && grid[y - 1][x]) {
						que.emplace(make_tuple(y - 1, x, d + 1));
					}
					if (y + 1 < h && grid[y + 1][x]) {
						que.emplace(make_tuple(y + 1, x, d + 1));
					}
					if (x > 0 && grid[y][x - 1]) {
						que.emplace(make_tuple(y, x - 1, d + 1));
					}
					if (x + 1 < w && grid[y][x + 1]) {
						que.emplace(make_tuple(y, x + 1, d + 1));
					}
				}
			}
		}

		int length = graph[0].size();
		if (length != cnt) {
			cout << -1<<endl;
			continue;
		}

		vector<int> pats;
		for (int i = 1; i < points.size(); i++)pats.emplace_back(i);

		int res =1e9;
		do {
			int tmp = 0;
			int prev = 0;
			for (int i = 0; i < pats.size(); i++) {
				tmp += graph[prev][pats[i]];
				prev = pats[i];
			}
			res = min(res, tmp);
		} while (next_permutation(pats.begin(), pats.end()));

		cout << res << endl;
	}
}
