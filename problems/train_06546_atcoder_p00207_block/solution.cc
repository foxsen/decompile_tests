#include <bits/stdc++.h>

#define FOR(i, j, k) for(int i = j; i < k; ++i)
#define rep(i, j) FOR(i, 0, j)
#define MAX 101

using namespace std;

int field[MAX][MAX];
bool went[MAX][MAX];
int w, h;
int sx, sy, gx, gy;
int scol;
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

bool dfs(int x, int y) {
	if(field[y][x] == 0) return false;
	if(x == gx && y == gy) return true;
	int ncol = field[y][x];
	field[y][x] = 0;
	rep(i, 4) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(0 < nx && nx <= w && 0 < ny && ny <= h && ncol == field[ny][nx]) {
			/*rep(j, h) {
				rep(k, w) cout << field[j][k] << " ";
				cout << endl;
			}*/
			if(dfs(nx, ny)) return true;
		}
	}
	return false;
}

int main() {
	while(cin >> w >> h, w || h) {
		memset(field, 0, sizeof(field));
		memset(went, false, sizeof(went));
		int n;
		cin >> sx >> sy >> gx >> gy;
		cin >> n;
		rep(i, n) {
			int c, d, x, y;
			cin >> c >> d >> x >> y;
			rep(i, (d ? 4 : 2)) rep(j, (d ? 2 : 4)) field[y + i][x + j] = c;
		}
		/*rep(j, h) {
			rep(k, w) cout << field[j][k] << " ";
			cout << endl;
		}*/
		if(dfs(sx, sy)) cout << "OK" << endl;
		else cout << "NG" << endl;
	}
	return 0;
}