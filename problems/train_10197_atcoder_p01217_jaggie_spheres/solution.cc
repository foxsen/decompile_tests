#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2000 + 10;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int n;
int len, o;
int flag;
int h[N][N];
int vis[N][N];

int valid(int x, int y)
{
	return x >= 0 && y >= 0 && vis[x][y] == flag;
}

void bfs(int sx, int sy)
{
	queue<pair<int, int> > que;
	que.push(make_pair(sx, sy));
	vis[sx][sy] = flag + 1;
	int nx, ny;
	int px, py;
	for( ; que.size(); ) {
		nx = que.front().first;
		ny = que.front().second;
		que.pop();
		for(int i = 0; i < 4; ++ i) {
			px = nx + dx[i];
			py = ny + dy[i];
			if (valid(px, py) && h[nx][ny] == h[px][py]) {
				vis[px][py] = flag + 1;
				que.push(make_pair(px, py));
			}
		}
	}
}

void solve()
{
	len = 0;
	for( ; len * len < n; ++ len);
	o = len;

	++ flag;
	for(int i = 0; i <= 2 * len + 2; ++ i)
		for(int j = 0; j <= 2 * len + 2; ++ j)
			h[i][j] = 0;
	for(int x = -len; x <= len; ++ x) {
		for(int y = -len; y <= len; ++ y) {
			h[x + o][y + o] = 0;
			if (x * x + y * y < n) {
				int tmp = sqrt(n - x * x - y * y);
				for( ; tmp * tmp + x * x + y * y < n; ++ tmp);
				for( ; tmp > 0 && (tmp - 1) * (tmp - 1) + x * x + y * y >= n; -- tmp);
				h[x + o][y + o] = tmp;
			}
			//cout << x << ' ' << y << ' ' << h[x + o][y + o] << endl;
			vis[x + o][y + o] = flag;
		}
	}
	for(int i = 0; i <= 2 * len; ++ i) {
		for(int j = 0; j <= 2 * len; ++ j) {
			if (vis[i][j] == flag || vis[i + 1][j] == flag || vis[i][j + 1] == flag || vis[i + 1][j + 1] == flag) {
				h[i][j] = max(max(h[i][j], h[i + 1][j + 1]), max(h[i][j + 1], h[i + 1][j]));
				if (h[i][j] <= 0) continue;
				//cout << i << ' ' << j << ' ' << h[i][j] << endl;
				vis[i][j] = flag + 1;
			}
		}
	}
	++ flag;
	int ret = 0;
	for(int i = 0; i <= 2 * len; ++ i) {
		for(int j = 0; j <= 2 * len; ++ j) {
			if (vis[i][j] == flag) {
				ret += 6;
				bfs(i, j);
			}
		}
	}
	++ flag;
	cout << ret << endl;
}

int main()
{
	flag = 0;
	for( ; cin >> n && n; ) {
		solve();
	}
	return 0;
}