#include"bits/stdc++.h"
using namespace std;
int main() {
	int n, a, b, c;
	int masatoy[101];
	int max = 0;
	cin >> n;
	cin >> a >> b;
	cin >> c;
	max = c / a;
	for (int i = 0; i < n; i++) {
		cin >> masatoy[i];
	}
	int nedan = a;
	sort(masatoy, masatoy + n);
	for (int i = n - 1; i > -1; i--) {
		nedan += b;
		c += masatoy[i];
		int max2 = (c) / nedan;
		if (max2 > max) { max = max2; }
	}
	cout << max << endl;
}
	