#include<iostream>
#include<queue>
using namespace std;
struct Puzzle { char p[10][10]; };
queue<pair<Puzzle, int>>Q;
queue<pair<int, int> >Q2;
int blute_force(int h, int w, Puzzle x) {
	while (!Q.empty())Q.pop();
	Q.push(make_pair(x, 0));
	while (true) {
		Puzzle y = Q.front().first; int V = Q.front().second; Q.pop();
		int a[3] = { 0,0,0 };
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (y.p[i][j] == 'R')a[0]++;
				if (y.p[i][j] == 'G')a[1]++;
				if (y.p[i][j] == 'B')a[2]++;
			}
		}
		if (a[0] == h*w || a[1] == h*w || a[2] == h*w)return V;
		char F[3] = { 'R','G','B' };
		for (int i = 0; i < 3; i++) {
			if (F[i] == y.p[0][0])continue;
			int dx[4] = { 0,1,0,-1 };
			int dy[4] = { 1,0,-1,0 };
			Puzzle v = y; Q2.push(make_pair(0, 0)); v.p[0][0] = F[i];
			while (!Q2.empty()) {
				int cx = Q2.front().first, cy = Q2.front().second; Q2.pop();
				for (int j = 0; j < 4; j++) {
					int ex = cx + dx[j], ey = cy + dy[j];
					if (ex < 0 || ey < 0 || ex >= h || ey >= w)continue;
					if (y.p[ex][ey] == y.p[0][0] && v.p[ex][ey] == y.p[ex][ey]) {
						Q2.push(make_pair(ex, ey)); v.p[ex][ey] = F[i];
					}
				}
			}
			Q.push(make_pair(v, V + 1));
		}
	}
}
int main() {
	while (true) {
		Puzzle x; int H, W; cin >> W >> H;
		if (W + H == 0)break;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> x.p[i][j];
			}
		}
		cout << blute_force(H, W, x) << endl;
	}
	return 0;
}