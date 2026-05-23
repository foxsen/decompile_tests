#include <cstdio>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int N, L, s, t, u, x[172809];
int main() {
	while (scanf("%d%d", &N, &L), N) {
		fill(x, x + 172800, 0);
		for (int i = 0; i < N; i++) {
			scanf("%d%d%d", &s, &t, &u);
			for (int j = s; j < t; j++) x[j] = u, x[j + 86400] = u;
		}
		double l = 0, r = 1.0e+7;
		for (int i = 0; i < 70; i++) {
			double m = (l + r) * 0.5;
			double s = L; bool flag = true, f2 = false;
			for (int j = 0; j < 172800; j++) {
				s += m - x[j];
				s = min(s, 1.0 * L);
				if (s < -1.0e-7) {
					flag = false;
					break;
				}
				if (j >= 86400 && s >= L - 1.0e-7) f2 = true;
			}
			if (flag && f2) r = m;
			else l = m;
		}
		printf("%.12lf\n", l);
	}
	return 0;
}