#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T>
class fenwick_tree {
	const int n;
	vector<T> data;
public:
	fenwick_tree(int n_) : n(n_), data(n + 1) {}
	T find(int p) const {
		T res = 0;
		while (p > 0) {
			res += data[p];
			p -= p & -p;
		}
		return res;
	}
	T find(int l, int r) const {
		return find(r) - find(l);
	}
	void add(int p, T val) {
		++p;
		while (p <= n) {
			data[p] += val;
			p += p & -p;
		}
	}
};

int main()
{
	int n;
	cin >> n;
	vector<pair<ll, int>> sp(n);
	vector<ll> l(n);
	for (int i = 0; i < n; i++) {
		sp[i].second = i;
		cin >> sp[i].first;
		if (0 <= i - 1) sp[i].first += sp[i - 1].first;
	}
	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}
	sort(sp.begin(), sp.end() - 1);
	bool ng = false;
	vector<pair<int, int>> all;
	for (int i = 0; i < n; i++) {
		if ((i ? sp[i].first - sp[i - 1].first : sp[i].first) < l[i]) {
			ng = true;
			break;
		}
		if (i + 1 < n) all.emplace_back(sp[i].second, i);
	}
	if (ng) {
		cout << -1 << endl;
		return 0;
	}
	sort(all.begin(), all.end());
	ll res = 0;
	fenwick_tree<int> ft(n);
	for (auto p : all) {
		res += ft.find(p.second, n);
		ft.add(p.second, 1);
	}
	cout << res << endl;
	return 0;
}

