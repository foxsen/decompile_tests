#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define int long long
using namespace std;
int n, a[20], k;
bool b[20];
void f(int i, int p) {
	if (i < 0) {
		if (p != k)return;
		int r = 0;
		for (int p = 0; p < n; p++) if (b[p]) r += a[p];
		cout << r << ':';
		for (int p = 0; p < n; p++)if (b[p])cout << ' ' << p;
		cout << endl;
		return;
	}
	b[i] = 0;
	f(i - 1, p);
	b[i] = 1;
	f(i - 1, p + 1);
	return;
}
signed main() {
	cin >> n >> k;
	a[0] = 1;
	for (int i = 1; i < n; i++)a[i] = a[i - 1] * 2;
	f(n - 1, 0);
}
