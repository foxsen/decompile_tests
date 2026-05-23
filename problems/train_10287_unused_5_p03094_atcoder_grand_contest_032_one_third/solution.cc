#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
const int mod = 1e9 + 7;
const int N = 1000010, inv3 = (mod + 1) / 3;
int n, ans, ba = 1;
int inv[N];

int main() {
	scanf("%d", &n), inv[0] = inv[1] = 1;
	rep(i, 2, n) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	rep(i, 1, n) {
		ba = 1ll * ba * inv3 % mod;
		ans = (ans + 1ll * inv[n - i + 1] * ba) % mod;
	}
	printf("%lld\n", 1ll * ans * inv[n] % mod);
	return 0;
}