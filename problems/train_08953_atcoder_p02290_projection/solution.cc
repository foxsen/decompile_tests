#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	int q; cin >> q;
	long double theta1, theta2;
	theta1 = atan2(y2 - y1, x2 - x1);
	while (q--) {
		int x, y; cin >> x >> y;
		theta2 = atan2(y - y1, x - x1);
		long double dist_x = hypot(x - x1,y - y1) * cos(theta2 - theta1);
		cout << fixed << setprecision(11) << x1 +  dist_x * cos(theta1) << " " << y1 + dist_x * sin(theta1) << endl;
	}
}