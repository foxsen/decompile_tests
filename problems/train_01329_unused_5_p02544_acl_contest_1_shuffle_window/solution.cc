#include <stdio.h>
#include <string.h>
using namespace std;

typedef long long int ll;
constexpr int kMod = 998244353, kN = int(2E5 + 10);

struct BIT {
	ll val[kN];
	void init() {memset(val, 0, sizeof(val));}
	void add(int pos, ll x) {
		while (pos < kN) {
			val[pos] = (val[pos] + x) % kMod;
			pos += pos & -pos;
		}
		return ;
	}
	ll ask(int pos) {
		ll ans = 0;
		while (pos){
			ans += val[pos];
			pos ^= pos & -pos;
		}
		return ans % kMod;
	}
};

ll Pow(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % kMod;
		a = a * a % kMod;
		b >>= 1;
	}
	return ans;
}

ll Rev(ll n) {return Pow(n, kMod - 2);}

int a[kN], f[kN];
ll p[kN];
BIT bit, bcnt;

int main() {
	int n, k;
	ll ans = 0, tot = 0, sum = 0;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	p[0] = 1;
	p[1] = (k - 1) * Rev(k) % kMod;
	for (int i = 2; i <= n; i++) p[i] = p[i - 1] * p[1] % kMod;
	for (int i = 1; i <= k; i++) f[i] = 0;
	for (int i = k + 1; i <= n; i++) f[i] = i - k;
	bit.init();
	bcnt.init();
	for (int i = 1; i <= n; i++) {
		ans += p[f[i]] * tot % kMod;
		ans -= p[f[i]] * (tot + tot - bit.ask(a[i])) % kMod;
		ans += (i - 1 - bcnt.ask(a[i]));
		bit.add(a[i], Rev(p[f[i]]));
		bcnt.add(a[i], 1);
		tot = (tot + Rev(p[f[i]]) * Rev(2)) % kMod;
	}
	ans %= kMod;
	if (ans < 0) ans += kMod;
	printf("%lld\n", ans);
}
