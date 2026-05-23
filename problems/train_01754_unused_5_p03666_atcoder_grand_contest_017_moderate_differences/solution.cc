#include <stdio.h>
long long n, a, b, c, d, e;
int main() {
	scanf("%lld%lld%lld%lld%lld", &n, &a, &b, &c, &d);
	n--;
	for (long long i = 0; i <= n; i++) {
		if (c * i - d * (n - i) <= a - b && a - b <= d * i - c * (n - i))e = 1;
	}
	if (e)printf("YES\n");
	else printf("NO\n");
}