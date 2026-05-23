#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long Int;
#define MAX_N 60

int N, K;
Int X1[MAX_N], Y1[MAX_N], Z1[MAX_N];
Int X2[MAX_N], Y2[MAX_N], Z2[MAX_N];

int xsLen, ysLen, zsLen;
Int xs[MAX_N * 2], ys[MAX_N * 2], zs[MAX_N * 2];

int main() {
	int i;
	int a, b, c;

	scanf("%d%d", &N, &K);
	for (i = 0; i < N; ++i) {
		scanf("%lld%lld%lld", &X1[i], &Y1[i], &Z1[i]);
		scanf("%lld%lld%lld", &X2[i], &Y2[i], &Z2[i]);
	}

	xsLen = ysLen = zsLen = 0;
	for (i = 0; i < N; ++i) {
		xs[xsLen++] = X1[i]; ys[ysLen++] = Y1[i]; zs[zsLen++] = Z1[i];
		xs[xsLen++] = X2[i]; ys[ysLen++] = Y2[i]; zs[zsLen++] = Z2[i];
	}
	sort(xs, xs + xsLen); sort(ys, ys + ysLen); sort(zs, zs + zsLen);

	Int ans = 0;
	for (a = 0; a < xsLen - 1; ++a)
		for (b = 0; b < ysLen - 1; ++b)
			for (c = 0; c < zsLen - 1; ++c)
			{
				int cnt = 0;
				for (i = 0; i < N; ++i) {
					if (
						X1[i] <= xs[a] && xs[a + 1] <= X2[i] &&
						Y1[i] <= ys[b] && ys[b + 1] <= Y2[i] &&
						Z1[i] <= zs[c] && zs[c + 1] <= Z2[i]
						) {
						++cnt;
					}
				}
				if (cnt >= K) {
					ans += (xs[a + 1] - xs[a]) * (ys[b + 1] - ys[b]) * (zs[c + 1] - zs[c]);
				}
			}
	printf("%lld\n", ans);

	return 0;
}
