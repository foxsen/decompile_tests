
#include <stdio.h>
#include <map>
#include <vector>

int absi(int i) {
	if (i > 0) return i;
	else return -i;
}

int main()
{
	int T;
	scanf("%d", &T);

	while (T--) {
		int n;
		long long ans = 0;
		scanf("%d", &n);
		std::vector<int> tag(n + 1);
		std::vector<int> s(n + 1);
		std::vector<long long> d(n + 1, 0);
		for (int i = 1; i <= n; i++) scanf("%d", &tag[i]);
		for (int i = 1; i <= n; i++) scanf("%d", &s[i]);

		for (int t = 2; t <= n; t++) {
			for (int i = t - 1; i >= 1; i--) {
				if (tag[t] != tag[i]) {
					long long di = d[i];
					long long dt = d[t];
					long long ss = absi(s[i] - s[t]);
					d[t] = std::max(di + ss, dt);
					d[i] = std::max(dt + ss, di);

					ans = std::max(ans, d[i]);
					ans = std::max(ans, d[t]);
				}
			}
		}

		printf("%lld\n", ans);
	}

	return 0;
}