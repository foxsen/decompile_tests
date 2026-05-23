#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n;
struct point {
	double x, y;
	bool operator < (point rhs) const {
		return atan2(y, x) < atan2(rhs.y, rhs.x);
	}
} p[N];
double X = 0.0, Y = 0.0, ans = 0.0;
int main () {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%lf%lf", &p[i].x, &p[i].y);
	sort(p, p + n);
	for (int i = 0; i < n; i++) {
		int j = i;
		X = 0.0, Y = 0.0;
		do {
			X += p[j].x, Y += p[j].y;
			ans = max(ans, sqrt(X * X + Y * Y));
			j = (j + 1) % n;
		} while (j != i);
	}
	printf("%.15lf\n", ans);
	return 0;
}
