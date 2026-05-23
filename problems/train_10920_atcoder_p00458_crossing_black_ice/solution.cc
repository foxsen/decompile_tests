#include <iostream>
#include <cstring>
using namespace std;

int w, h;
int map[91][91];
bool visited[91][91];

int dx[] = { 0, 1, 0, -1};
int dy[] = {-1, 0, 1,  0};

int dfs(int x, int y, int n) {
	int result = n;
	// 到達した時の処理： count を増やす
	for (int i = 0; i < 4; i++) {
		int nextX = dx[i] + x;
		int nextY = dy[i] + y;
		// point: 範囲外と'.'で無い場合は外す
		if (0 <= nextX && nextX < w && 0 <= nextY && nextY < h
				&& !visited[nextY][nextX] && map[nextY][nextX] == 1) {
			visited[nextY][nextX] = true;
			result = max(result, dfs(nextX, nextY, n + 1));
			visited[nextY][nextX] = false;
		}
	}
	return result;
}

int main() {
	
	while (cin >> w >> h, w || h) {
		// 前回の文字列の入力を参照
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}
		int maxBreak = 0;
		for (int i = 0; i < h; i++) {
			fill(visited[i], visited[i] + w, false);
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1) {
					maxBreak = max(maxBreak, dfs(j, i, 0));
				}
			}
		}
		cout << maxBreak << endl;
	}
	return 0;
}