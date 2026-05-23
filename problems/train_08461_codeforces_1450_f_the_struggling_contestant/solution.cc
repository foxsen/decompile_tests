#include <bits/stdc++.h>
using namespace std;

const int N = 300 * 1000 + 5;

int a[N], cnt[N], c[N];

int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		int n, ans = 0;
		cin >> n;
		
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			c[a[i]]++;
			if (i > 1 && a[i] == a[i - 1]) {
				ans++;
				cnt[a[i]]++;
				cnt[a[i - 1]]++;
			}
		}
		cnt[a[1]]++;
		cnt[a[n]]++;
		for (int i = 1; i <= n; i++) {
			int x = a[i];
		//	cout << "71 " << i << " " << x << " " << c[x] << endl;
			if (c[x] > n - n / 2) {
				ans = N;
			}
			ans = max(ans, cnt[x] - 2);
			cnt[x] = c[x] = 0;
		}
		if (ans == N) {
			cout << -1;
		}
		else {
			cout << ans;
		}
		cout << '\n';
	}
	
	return 0;
}
