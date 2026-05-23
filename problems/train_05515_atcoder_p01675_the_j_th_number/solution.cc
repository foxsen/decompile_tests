#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int PMAX = 10000000;
const int QMAX = 100001;

const function<int(int, int)> minQ = [](int l, int r) { return min(l, r); };
const function<int(int, int)> maxQ = [](int l, int r) { return max(l, r); };
const function<ll(ll, ll)> minQll = [](ll l, ll r) { return min(l, r); };
const function<ll(ll, ll)> maxQll = [](ll l, ll r) { return max(l, r); };

template <typename T>
struct node {
	T val, add;
	node *l, *r;
	node() {}
	node(T val, T add) : val(val), add(add), l(nullptr), r(nullptr) {}
	void init(T v, T a, node *left, node *right) {
		val = v;
		add = a;
		l = left;
		r = right;
	}
};

node<ll> pool[PMAX];
node<ll> *root[QMAX];

template <typename T>
class SaikyoSegmentTree {
	using func_t = function<T(T, T)>;
	const ll n;
	const T id;
	func_t merge;
	int it, rit;
	T getval(node<T> *x) {
		return x == nullptr ? id : x->val;
	}
	T getadd(node<T> *x) {
		return x == nullptr ? id : x->add;
	}
	node<T>* getl(node<T> *x) {
		return x == nullptr ? nullptr : x->l;
	}
	node<T>* getr(node<T> *x) {
		return x == nullptr ? nullptr : x->r;
	}
	ll size(ll n) {
		assert(n < (1ll << 62ll));
		ll res = 1;
		while (res < n) res <<= 1;
		return res;
	}
	node<T> *new_node(T val, T add, node<T> *l = nullptr, node<T> *r = nullptr) {
		pool[it].init(val, add, l, r);
		return &pool[it++];
	}
	node<T> *fix(node<T> *x, ll l, ll r, T val, ll lb, ll ub) {
		if (r <= lb || ub <= l) return x;
		if (l <= lb && ub <= r) return new_node(getval(x), merge(getadd(x), val), getl(x), getr(x));
		ll c = (lb + ub) / 2;
		auto nl = fix(getl(x), l, r, val, lb, c);
		auto nr = fix(getr(x), l, r, val, c, ub);
		return new_node(getval(x) + val * (min(r, ub) - max(l, lb)), getadd(x), nl, nr);
	}
	T sub(node<T> *x, ll l, ll r, ll lb, ll ub) {
		if (x == nullptr) return id;
		if (ub <= l || r <= lb) return id;
		if (l <= lb && ub <= r) return x->val + x->add * (ub - lb);
		ll c = (lb + ub) / 2;
		return merge(sub(getl(x), l, r, lb, c), sub(getr(x), l, r, c, ub)) + x->add * (min(r, ub) - max(l, lb));
	}
public:
	SaikyoSegmentTree(ll n_, T id_, func_t merge_) : n(size(n_)), id(id_), merge(merge_), it(0), rit(0) {
		root[rit++] = nullptr;
	}
	void add(ll l, ll r, T val, int rt = -1) {
		if (rt == -1) rt = rit - 1;
		assert(0 <= rt && rt < rit);
		root[rit++] = fix(root[rt], l, r + 1, val, 0, n);
	}
	T find(ll l, ll r, int rt = -1) {
		if (rt == -1) rt = rit - 1;
		assert(0 <= rt && rt < rit);
		return sub(root[rt], l, r + 1, 0, n);
	}
};

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
	ll N, M, Q;
	cin >> N >> M >> Q;
	vector<tuple<int, int, int>> vab(M);
	for (int i = 0; i < M; i++) {
		cin >> get<1>(vab[i]) >> get<2>(vab[i]) >> get<0>(vab[i]); get<1>(vab[i])--; get<2>(vab[i])--;
	}
	sort(vab.begin(), vab.end());
	SaikyoSegmentTree<ll> sst(N, 0, [](ll l, ll r) { return l + r; });
	for (int i = 0; i < M; i++) {
		sst.add(get<1>(vab[i]), get<2>(vab[i]), 1);
	}
	ll x, y, j;
	while (Q--) {
		cin >> x >> y >> j; x--; y--;
		ll l = 0, r = M;
		while(l + 1 < r) {
			ll c = (l + r) / 2;
			if (sst.find(x, y, c) >= j) {
				r = c;
			}
			else {
				l = c;
			}
		}
		printf("%d\n", get<0>(vab[r - 1]));
	}
	return 0;
}