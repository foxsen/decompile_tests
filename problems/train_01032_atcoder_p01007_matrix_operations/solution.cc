#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
#include <map>
#include <queue>
#include <cassert>
using namespace std;

int arr[15][15];
int t[15][15];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			assert(i < 15 && j < 15);
			cin >> arr[i][j];
		}
	}
	int o;
	for (int i=0; i<m; ++i) {
		cin >> o;
		int r, c, size, angle;
		if (o == 0) {
			cin >> r >> c >> size >> angle;
			--r, --c;
			if (angle == 0 || angle == 360) {
				// pass
			} else if (angle == 90) {
				memcpy(t, arr, sizeof t);
				for (int j=0; j<size; ++j) {
					for (int k=0; k<size; ++k) {
						assert(r+j < 15 && c+k < 15);
						assert(0 <= r+j && 0 <= c+k);
						assert(r+size-1-k < 15 && c+j < 15);
						assert(0 <= r+size-1-k && 0 <= c+j);
						arr[r+j][c+k] = t[r+size-1-k][c+j];
					}
				}
			} else if (angle == 180) {
				memcpy(t, arr, sizeof t);
				for (int j=0; j<size; ++j) {
					for (int k=0; k<size; ++k) {
						assert(r+j < 15 && c+k < 15);
						assert(r+size-1-j < 15 && c+size-1-k < 15);
						arr[r+j][c+k] = t[r+size-1-j][c+size-1-k];
					}
				}
			} else if (angle == 270) {
				memcpy(t, arr, sizeof t);
				for (int j=0; j<size; ++j) {
					for (int k=0; k<size; ++k) {
						assert(r+j < 15 && c+k < 15);
						assert(r+k < 15 && c+size-1-j < 15);
						arr[r+j][c+k] = t[r+k][c+size-1-j];
					}
				}
			}
		} else if (o == 1) {
			cin >> r >> c >> size;
			--r, --c;
			for (int j=r; j<r+size; ++j) {
				for (int k=c; k<c+size; ++k) {
					arr[j][k] = 1 - arr[j][k];
				}
			}
		} else if (o == 2) {
			cin >> r;
			--r;
			rotate(arr[r], arr[r]+1, arr[r]+n);
		} else if (o == 3) {
			cin >> r;
			--r;
			rotate(arr[r], arr[r]+n-1, arr[r]+n);
		} else {
			cin >> r >> c;
			--r, --c;
			queue<pair<int,int> > q;
			q.push(make_pair(r, c));
			int v = 1 - arr[r][c];
			while ( ! q.empty()) {
				int nr = q.front().first;
				int nc = q.front().second;
				q.pop();
				if (arr[nr][nc] == v) continue;
				arr[nr][nc] = v;
				if (nr+1 < n) q.push(make_pair(nr+1, nc));
				if (0 <= nr-1) q.push(make_pair(nr-1, nc));
				if (nc+1 < n) q.push(make_pair(nr, nc+1));
				if (0 <= nc-1) q.push(make_pair(nr, nc-1));
			}
		}
	}
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cout << (j == 0 ? "" : " ") << arr[i][j];
		}
		cout << endl;
	}
	return 0;
}