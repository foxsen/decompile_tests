#include <bits/stdc++.h>

using namespace std;

int	solve(void) {
	int n; cin >> n;
	int arr[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	if (arr[0] == arr[1] && arr[0] != arr[2])
		return (3);
	if (arr[0] == arr[2] && arr[0] != arr[1])
		return (2);
	if (arr[1] == arr[2] && arr[0] != arr[1])
		return (1);
	for (int i = 3; i < n; i++)
		if (arr[i] != arr[i - 1])
			return (i += 1);
	return (0);
}

int	main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;

	cin >> t;
	for (int i = 1; i <= t; i++)
		cout << solve() << endl;
	return (0);
}