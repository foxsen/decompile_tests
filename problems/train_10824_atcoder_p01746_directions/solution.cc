#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-9;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int gcd(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<long double>x(N);
	vector<long double>y(N);
	vector<long long int>p(N);
	vector<pair<long double, long long int>>v;
	map<pair<int, int>, long long int>mp;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b >> p[i];
		if (a == 0 && b == 0)continue;
		int g = gcd(abs(a), abs(b));
		a /= g;
		b /= g;
		if (mp[{a, b}] == 0)mp[{a, b}] = MOD;
		mp[{a, b}] = min(mp[{a, b}], p[i]);
		x[i] = a, y[i] = b;
		if (x[i] || y[i]) {
			v.push_back({ atan2l(y[i], x[i]), p[i] });
		}
	}
	sort(v.begin(), v.end());
	M = v.size();
	long double pi = acosl(-1);
	for (int i = 0; i < M; i++) {
		v.push_back({ v[i].first + pi * 2,v[i].second });
	}
	for (int i = 0; i < M; i++) {
		v.push_back({ v[i].first + pi * 4,v[i].second });
	}
	long long int ret = MOD * MOD;
	for(int loop=0;loop<2;loop++){
		set<pair<long long int, int>>fst;
		set<pair<long long int, int>>snd;
		int a = 0, b = 0, c = 0, d = 0;
		for (int i = 1; i < M * 3; i++) {
			if (v[i].first <= v[0].first + pi / 2-EPS)a = i;
			else if (v[i].first < v[0].first + pi - EPS) {
				b = i;
				fst.insert({ v[i].second,i });
			}
			else if (v[i].first <= v[0].first + pi + EPS) {
				c = i;
			}
			else if (v[i].first <= v[0].first + pi * 3 / 2-EPS) {
				d = i;
				snd.insert({ v[i].second,i });
			}
			b = max(a, b);
			c = max(c, b);
			d = max(c, d);
		}
		a++, b++, c++, d++;
		long long int ans = MOD * MOD;
		if (!fst.empty() && !snd.empty()) {
			ans = min(ans, v[0].second + fst.begin()->first + snd.begin()->first);
		}
		for (int i = 1; i < M; i++) {
			while (v[b].first < v[i].first + pi - EPS) {
				fst.insert({ v[b].second,b });
				b++;
			}
			while (v[a].first <= v[i].first + pi / 2-EPS) {
				fst.erase({ v[a].second,a });
				a++;
			}
			while (v[d].first <= v[i].first + pi * 3 / 2-EPS) {
				snd.insert({ v[d].second,d });
				d++;
			}
			while (v[c].first <= v[i].first + pi + EPS) {
				snd.erase({ v[c].second,c });
				c++;
			}
			if (!fst.empty() && !snd.empty()) {
				ans = min(ans, v[i].second + fst.begin()->first + snd.begin()->first);
			}
		}
		ret = min(ret, ans);
		for (auto &i : v) {
			i.first = -i.first;
		}
		reverse(v.begin(), v.end());
	}
	vector<long long int>pa;
	for (auto i : mp) {
		if (i.first.second <= 0 && !(i.first.first == 1 && i.first.second == 0)) {
			if (mp.find({ -i.first.first,-i.first.second }) != mp.end()) {
				pa.push_back(i.second + mp[{-i.first.first, -i.first.second}]);
			}
		}
	}
	sort(pa.begin(), pa.end());
	if (pa.size() > 1) {
		ret = min(ret, pa[0] + pa[1]);
	}
	if (ret == MOD * MOD)ret = -1;
	cout << ret << endl;
}
