#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, C;
	cin >> N >> C;
	vector<unsigned long long> val(N), vc; // Upper bound: N * (C * max(p) + 1) - 1
	for (int i = 0; i < N; ++i) {
		val[i] = N - i - 1;
		vc.push_back(val[i]);
	}
	vector<int> tp(C), a(C), b(C);
	for (int i = 0; i < C; ++i) {
		cin >> tp[i] >> a[i]; --a[i];
		if (tp[i] == 0) {
			cin >> b[i];
			val[a[i]] += 1LL * N * b[i];
			vc.push_back(val[a[i]]);
		}
	}
	sort(vc.begin(), vc.end());
	for (int i = 0; i < N; ++i) {
		val[i] = N - i - 1;
	}
	int sz = 1;
	while (sz < vc.size()) sz *= 2;
	vector<int> bit(sz + 1);
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j <= sz; j += j & (-j)) {
			++bit[j];
		}
	}
	for (int i = 0; i < C; ++i) {
		if (tp[i] == 0) {
			int ptr_old = lower_bound(vc.begin(), vc.end(), val[a[i]]) - vc.begin();
			val[a[i]] += 1LL * N * b[i];
			int ptr_new = lower_bound(vc.begin(), vc.end(), val[a[i]]) - vc.begin();
			for (int j = ptr_old + 1; j <= sz; j += j & (-j)) {
				--bit[j];
			}
			for (int j = ptr_new + 1; j <= sz; j += j & (-j)) {
				++bit[j];
			}
		}
		else {
			int cur = 0, pos = 0;
			for (int j = sz / 2; j >= 1; j >>= 1) {
				if (cur + bit[pos + j] < N - a[i]) {
					pos += j;
					cur += bit[pos];
				}
			}
			cout << N - vc[pos] % N << ' ' << vc[pos] / N << '\n';
		}
	}
	return 0;
}
