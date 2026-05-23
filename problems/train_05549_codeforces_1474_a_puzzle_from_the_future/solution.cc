#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int arr[n];
	int i = 0;
	for (auto ch : s)
		arr[i++] = ch - '0';
	int last = arr[0] + 1;
	int ans[n];
	ans[0] = 1;
	for (int i = 1; i < n; i++) {
		int temp = 1;
		int curr = arr[i] + 1;
		if (curr == last) {
			temp = 0;
		}
		ans[i] = (temp);
		last = arr[i] + temp;
	}
	for (int i = 0; i < n; i++)
		cout << ans[i];
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}