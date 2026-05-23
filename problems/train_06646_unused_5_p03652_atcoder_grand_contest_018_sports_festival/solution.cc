#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j]; --A[i][j];
		}
	}
	int res = 1 << 30;
	vector<int> use(M, 1);
	int loop = M;
	while (loop) {
		vector<int> cnt(M, 0);
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (use[A[i][j]]) {
					++cnt[A[i][j]];
					break;
				}
			}
		}
		auto iter = max_element(cnt.begin(), cnt.end());
		res = min(res, *iter);
		int del_sp = iter -cnt.begin();
		use[del_sp] = 0;
		--loop;
	}
	cout << res << endl;
	return 0;
}