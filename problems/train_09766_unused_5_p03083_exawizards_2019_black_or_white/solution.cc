#include <stdio.h>
#include <algorithm>
long long ansy, ansx;
long long e, f;
long long b, w;
long long p = 1000 * 1000 * 1000 + 7;
long long beki[200005];
long long kai[200005];
long long rui(long long a, long long b) {
	if (b == 0)return 1;
	if (b == 1)return a % p;
	if (b == 2)return a * a%p;
	if (b % 2 == 1) {
		return (rui(rui(a, b / 2), 2))*a%p;
	}
	else return rui(rui(a, b / 2), 2) % p;
}
long long inv(long long a) {
	return rui(a, p - 2);
}
int main() {
	beki[0] = 1;
	for (int i = 1; i < 200005; i++)beki[i] = beki[i - 1] * 2 % p;
	kai[0] = 1;
	for (int i = 1; i < 200005; i++)kai[i] = i * kai[i - 1] % p;
	scanf("%lld%lld", &b, &w);
	for (long long i = 0; i < w + b; i++) {
		ansy = beki[i];
		if (i >= w) {
			e = e * 2 + kai[i - 1] * inv(kai[i - w] * kai[w - 1] % p);
			e %= p;
		}
		if (i >= b) {
			f = f * 2 + kai[i - 1] * inv(kai[i - b] * kai[b - 1] % p);
			f %= p;
		}
		ansy += e;
		ansy -= f;
		ansy += p;
		ansy %= p;
		ansx = beki[i + 1];
		printf("%lld\n", ansy*inv(ansx) % p);
	}
}