#include <bits/stdc++.h>
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	map<int,int> cnt;
	for (int i = 0; i < N; ++ i) {
		int x;
		cin >> x;
		++cnt[x];
	}
	map<int,int> a;
	map<int,int> b;
	for (auto p : cnt) {
		a[p.first % M] += p.second;
		b[p.first % M] += p.second / 2;
	}
	int r = 0;
	for (int i = 0; i <= M-i; ++ i) {
		if (i == 0 || i == M-i) {
			r += a[i] / 2;
		} else {
			int p = min(a[i], a[M-i]);
			r += p;
			a[i] -= p;
			a[M-i] -= p;
			r += min(a[i]/2, b[i]);
			r += min(a[M-i]/2, b[M-i]);
		}
	}
	cout << r << endl;
}
