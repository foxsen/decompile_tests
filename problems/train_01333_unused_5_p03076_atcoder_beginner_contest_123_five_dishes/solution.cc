#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define int long long
using namespace std;
signed main() {
	int ans = 0, p = 0;
	for (int i = 0; i < 5; i++) {
		int t; cin >> t;
		int t1 = (t + 9) / 10 * 10;
		ans += t1;
		p = max(p, t1 - t);
	}
	cout << ans - p << endl;
}