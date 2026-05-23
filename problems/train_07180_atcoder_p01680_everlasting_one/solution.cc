#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class union_find {
private:
	vector<int> uf;

	int find(int x) {
		return uf[x] < 0 ? x : uf[x] = find(uf[x]);
	}

public:
	explicit union_find(int n):uf(n, -1) {}

	void unite(int x, int y) {
		x = find(x);
		y = find(y);

		if(x == y) return;

		if(uf[x] > uf[y]) swap(x, y);

		uf[x] += uf[y];
		uf[y] = x;
	}

	int number_of_sets() const {
		return count_if(begin(uf), end(uf), [](int x) { return x < 0; });
	}
};

constexpr long long mod = 1000000007;

long long mod_pow(long long n, long long k) {
	long long res = 1;

	while(k > 0) {
		if(k & 1) res = (res * n) % mod;
		n = (n * n) % mod;
		k >>= 1;
	}

	return res;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	for(int n, m; cin >> n >> m && n;) {
		union_find uf(n);

		for(int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;
			uf.unite(a - 1, b - 1);
		}

		const int S = uf.number_of_sets();
		const auto ans = mod_pow(2, S);

		cout << (n == S ? ans : (ans + 1) % mod) << endl;
	}

	return EXIT_SUCCESS;
}