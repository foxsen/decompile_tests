#include "bits/stdc++.h"
using namespace std;
vector<vector<char>> masu, temp;
int h, w, n;

bool check() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w;j++) {
			if (temp[i][j] != '.')return false;
		}
	}
	return true;
}

void fall() {
	for (int i = h - 1; i > 0;i--) {
		for (int j = w - 1; j >= 0; j--) {
			if (temp[i][j] != '.') continue;
			for (int k = i - 1; k >= 0;k--) {
				if (temp[k][j] == '.')continue;
				temp[i][j] = temp[k][j];
				temp[k][j] = '.';
				break;
			}
		}
	}
}

bool erase() {
	vector<vector<int>> f(h, vector<int>(w, 0));

	for (int i = 0; i < h;i++) {
		for (int j = 0; j < w;j++) {
			if (temp[i][j] == '.') continue;
			int Count = 0;
			for (int k = j;k < w;k++) {
				if (temp[i][j] == temp[i][k]) Count++;
				else break;
			}
			if (Count >= n) {
				for (int k = j;k < w;k++) {
					if (temp[i][j] == temp[i][k]) f[i][k] = 1;
					else break;
				}
			}
			Count = 0;
			for (int k = i;k < h;k++) {
				if (temp[i][j] == temp[k][j]) Count++;
				else break;
			}
			if (Count >= n) {
				for (int k = i;k < h;k++) {
					if (temp[i][j] == temp[k][j]) f[k][j] = 1;
					else break;
				}
			}
		}
	}
	bool ret = false;
	for (int i = 0; i < h;i++) {
		for (int j = 0; j < w;j++) {
			if (f[i][j] == 1) {
				temp[i][j] = '.';
				if (!ret) ret = true;
			}
		}
	}
	return ret;
}

bool solve() {
	fall();
	while (true) {
		if (!erase())break;
		fall();
	}
	return check();
}

int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	cin >> h >> w >> n;
	masu.resize(h, vector<char>(w));
	for (int i = 0; i < h;i++) for (int j = 0; j < w;j++) cin >> masu[i][j];

	for (int i = 0; i < h;i++) {
		for (int j = 0; j < w - 1;j++) {
			if (masu[i][j] == masu[i][j + 1]) continue;
			temp = masu;
			swap(temp[i][j], temp[i][j + 1]);

			if (solve()) {
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
}