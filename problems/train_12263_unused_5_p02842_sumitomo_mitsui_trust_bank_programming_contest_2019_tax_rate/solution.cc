#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++)
		if (i * 27 / 25 == n) {
			cout << i << endl;
			return 0;
		}
	cout << ":(" << endl;
}
