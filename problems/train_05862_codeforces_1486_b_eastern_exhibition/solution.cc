// Omar_Elaraby
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define EPS 1e-9

long long sumDists(const vector<ll> &x, const ll p) {
	long long ans = 0;
	for (int i = 0; i < x.size(); ++i) {
		ans += abs(x[i] - p);
	}
	return ans;
}

long long bestDist(const vector<ll> &x) {
	long long ans = LLONG_MAX;
	for (int i = 0; i < x.size(); ++i) {
		ans = min(ans, sumDists(x, x[i]));
	}
	return ans;
}

long long first(const vector<ll> &x, const ll bestDist) {
	for (int i = 0; i < x.size(); ++i) {
		if (sumDists(x, x[i]) == bestDist) return x[i];
	}
	assert(1 > 2);
}

long long last(const vector<ll> &x, const ll bestDist) {
	long long xx = -1;
	for (int i = 0; i < x.size(); ++i) {
		if (sumDists(x, x[i]) == bestDist) xx = x[i];
	}

	assert(xx != -1);
	return xx;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<ll> x(n), y(n);
		for (int i = 0; i < n; ++i) {
			cin >> x[i] >> y[i];
		}
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());

		long long bestDistX = bestDist(x);
		long long firstX = first(x, bestDistX);
		long long lastX = last(x, bestDistX);

		long long bestDistY = bestDist(y);
		long long firstY = first(y, bestDistY);
		long long lastY = last(y, bestDistY);

		cout << (lastX - firstX + 1LL) * (lastY - firstY + 1LL) << '\n';
	}

	return 0;
}
