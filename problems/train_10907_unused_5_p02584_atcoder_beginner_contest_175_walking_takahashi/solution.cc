#include <bits/stdc++.h>
using namespace std;

long long x, k, d;

int main() {
	scanf("%lld%lld%lld", &x, &k, &d);
	x = abs(x);
	if (x / d >= k)
		printf("%lld\n", x - k * d);
	else
		printf("%lld\n", x / d & 1 ^ k & 1 ? (x / d + 1) * d - x : x % d);
	return 0;
}

