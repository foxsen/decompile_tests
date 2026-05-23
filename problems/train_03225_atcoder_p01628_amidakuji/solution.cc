#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

template<class T> inline void chmin(T& a, const T& b) { if(b < a) a = b; }

int n, m;

vector<int> amida(const vector<int>& a) {
	vector<int> res;
	res.reserve(n);
	for(int i = 0; i < n; ++i) {
		int pos = i;
		for(int j = 0; j < m; ++j) {
			if(pos == a[j]) {
				--pos;
			}
			else if(pos + 1 == a[j]) {
				++pos;
			}
		}
		res.emplace_back(pos);
	}

	return res;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	vector<int> a(m);
	for(int i = 0; i < m; ++i) {
		cin >> a[i];
	}

	vector<int> goals = amida(a);

	sort(a.begin(), a.end());
	int ans = INT_MAX;

	do {
		if(goals == amida(a)) {
			vector<int> h(n + 1, 0);
			for(int i = 0; i < m; ++i)
				h[a[i]] = max({h[a[i] - 1], h[a[i]], h[a[i] + 1]}) + 1;

			chmin(ans, *max_element(h.begin(), h.end()));
		}
	} while(next_permutation(a.begin(), a.end()));

	cout << ans << endl;

	return EXIT_SUCCESS;
}