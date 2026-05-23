#include <iostream>
using namespace std;
constexpr int mod = 1000000007;
int n, inv[1000009];
int main() {
	cin >> n;
	inv[1] = 1;
	int cur = 1;
	for (int i = 2; i <= n; i++) {
		inv[i] = 1LL * inv[mod % i] * (mod - mod / i) % mod;
		cur = 1LL * cur * (i - 1) % mod;
	}
	int ret = 0;
	for (int i = n - 1; cur != 0; i--) {
		int x = 1LL * cur * inv[i] % mod * inv[i + 1] % mod * (2 * i - n + 2) % mod * (2 * i - n + 1) % mod;
		ret = (ret + 1LL * (cur - x + mod) * (i + 1)) % mod;
		cur = x;
	}
	cout << ret << "\n";
	return 0;
}