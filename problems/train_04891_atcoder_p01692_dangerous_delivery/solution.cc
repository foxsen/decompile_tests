// * template

#include <bits/stdc++.h>
#ifdef LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif

using namespace std;

template<class T> inline void chmax(T &a, const T &b) { if(a < b) a = b; }
template<class T> inline void chmin(T &a, const T &b) { if(a > b) a = b; }

template<class T, class U> inline void fill_array(T &e, const U &v) { e = v; }
template<class T, class U, size_t s> inline void fill_array(T (&a)[s], const U &v) {for(auto&e:a)fill_array(e,v);}
template<class T, class U, size_t s> inline void fill_array(array<T, s> &a, const U &v) {for(auto&e:a)fill_array(e,v);}
template<class T, class U> inline void fill_array(vector<T> &a, const U &v) {for(auto&e:a)fill_array(e,v);}

struct range {
	typedef int Int;
	struct iter {
		Int i;
		const Int s;
		iter(const Int &i_, const Int &s_):i(i_), s(s_) {}
		bool operator!=(const iter &r) const { return s > 0 ? i < r.i : i > r.i; }
		const Int &operator*() const { return i; }
		iter &operator++() { i += s; return *this; }
	};
	const Int f, l, s;
	range(const Int &f_, const Int &l_, const Int &s_):f(f_), l(l_), s(s_) {}
	range(const Int &f_, const Int &l_):f(f_), l(l_), s(1) {}
	range(const Int &num):f(0), l(num), s(1) {}
	iter begin() const { return iter(f, s); }
	iter end() const { return iter(l, s); }
};

// * solve

class BIT {
private:
	int size;
	vector<int> bit;

public:
	BIT(int n = 0):size(n), bit(n + 1, 0) {}

	void add(int i, int x) {
		++i;
		while(i <= size) {
			bit[i] += x;
			i += i & -i;
		}
	}

	int sum(int i) const {
		++i;
		int s = 0;
		while(i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}
};

struct line {
	typedef long long Int;
	Int a, b;
	line(Int a_, Int b_):a(a_), b(b_) {}
	Int operator()(Int x) const {
		return a * x + b;
	}
};

inline bool check(const line &f1, const line &f2, const line &f3) {
	return (f2.a - f1.a) * (f3.b - f2.b) >= (f2.b - f1.b) * (f3.a - f2.a);
}

constexpr int MAX_X = 1e6;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m, day, speed;
	cin >> n >> m >> day >> speed;

	vector<int> pos(n);
	for(auto &e : pos) cin >> e;

	BIT bit(MAX_X + 2);
	bit.add(0, m);

	vector<int> enemy(m);
	for(auto &e : enemy) {
		int a, b;
		cin >> a >> b;
		e = a - abs(b);
		bit.add(max(e + 1, 0), -1);
	}


	vector<long long> dp(n, 1e12);
	dp[0] = 0;

	const auto make_f = [&](int i) { const long long w = bit.sum(pos[i]); return line(w, dp[i] - w * pos[i]); };

	for(const int d : range(day)) {
		vector<long long> next_dp(dp);
		deque<line> deq{make_f(0)};
		for(const int i : range(1, n)) {
			const int &p = pos[i];

			while(deq.size() > 1 && deq[0](p) >= deq[1](p)) deq.pop_front();

			chmin(next_dp[i], deq.front()(p));

			const auto f = make_f(i);
			while(deq.size() > 1 && check(deq[deq.size() - 2], deq.back(), f)) deq.pop_back();
			deq.emplace_back(move(f));
		}

		dp = move(next_dp);
		dump(dp);
		for(auto &e : enemy) {
			bit.add(max(e + 1, 0), 1);
			e = min(e + speed, MAX_X + 1);
			bit.add(max(e + 1, 0), -1);
		}
	}

	cout << dp.back() << endl;

	return EXIT_SUCCESS;
}