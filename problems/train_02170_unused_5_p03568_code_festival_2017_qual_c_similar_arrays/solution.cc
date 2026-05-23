#include <bits/stdc++.h>
using namespace std;
int n, arr[110];
int main () {
	cin >> n;
	int ans = 1;
	int m = 1, t;
	for (int j = 0; j < n; j++) {
		ans *= 3;
		cin >> t;
		if (t & 1) m *= 1;
		else m *= 2;
	}
	cout << ans - m;
	return 0;
}