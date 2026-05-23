#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T>
class fenwick_tree{
	const int n;
	vector<T> dat;
public:
	fenwick_tree(int n_) : n(n_), dat(n, 0) {}
	void add(int i, T val){
		for(;i < n;i |= i + 1){
			dat[i] += val;
		}
	}
	T sum(int i) const {
		T res = 0;
		for(;i >= 0;i = (i & (i + 1)) - 1){
			res += dat[i];
		}
		return res;
	}
	T sum(int l, int r) const {
		return sum(r - 1) - sum(l - 1);
	}
};

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	vector<pair<int, int>> ai;
	for(int i = 0;i < n;i++){
		cin >> a[i];
		ai.emplace_back(a[i], i);
	}
	sort(ai.begin(), ai.end());
	fenwick_tree<int> ft(n);
	for(int i = 0;i < n;i++){
		ft.add(i, 1);
	}
	ll res = 0;
	for(int i = 0;i < n;){
		int val = ai[i].first;
		vector<int> ids;
		while(i < n && ai[i].first == val){
			ft.add(ai[i].second, -1);
			ids.push_back(ai[i++].second);
		}
		for(int id : ids){
			res += min(ft.sum(0, id), ft.sum(id, n));
		}
	}
	cout << res << endl;
	return 0;
}


