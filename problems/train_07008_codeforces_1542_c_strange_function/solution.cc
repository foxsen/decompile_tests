#include <stdio.h>

#define MD	1000000007

long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	int t;

	scanf("%d", &t);
	while (t--) {
		long long n, a, b, ans;

		scanf("%lld", &n);
		ans = n, b = 1;
		for (a = 1; a <= n; a++) {
			b *= a / gcd(a, b);
			if (b > n)
				break;
			ans = (ans + n / b) % MD;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
