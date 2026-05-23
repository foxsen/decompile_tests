#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const LL MOD = 1000000007LL;
vector<P> v;
bool appear[100000];
int main() {
	int R, C, N;
	cin >> R >> C >> N;
	for (int i = 0; i < N; i++) {
		int x[2], y[2];
		bool ok = 1;
		for (int j = 0; j < 2; j++) {
			cin >> x[j] >> y[j];
			if (x[j] != 0 && x[j] != R&&y[j] != 0 && y[j] != C) ok = 0;
		}
		if (!ok) continue;
		for (int j = 0; j < 2; j++) {
			if (y[j] == 0) {
				v.emplace_back(x[j], i);
			}
			else if (x[j] == R) {
				v.emplace_back(R + y[j], i);
			}
			else if (y[j] == C) {
				v.emplace_back(R + C + (R - x[j]), i);
			}
			else if (x[j] == 0) {
				v.emplace_back(R + C + R + (C - y[j]), i);
			}
		}
	}
	sort(v.begin(), v.end());
	stack<int> S;
	for (int i = 0; i < v.size(); i++) {
		if (appear[v[i].second]) {
			if (S.top() != v[i].second) {
				cout << "NO" << endl;
				return 0;
			}
			S.pop();
		}
		else {
			appear[v[i].second] = 1;
			S.push(v[i].second);
		}
	}
	cout << "YES" << endl;
}