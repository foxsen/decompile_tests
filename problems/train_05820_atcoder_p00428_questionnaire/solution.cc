#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
pair<int, int>x[8000000]; int n, m, s;
int main() {
	while (true) {
		for (int i = 0; i < 8000000; i++) { x[i].first = 1000000; }
		cin >> n >> m;
		if (!n) { break; }
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> s;
				x[j].first -= s;
				x[j].second = j;
			}
		}
		sort(x, x + m);
		for (int i = 0; i < m; i++) {
			if (i) { cout << ' '; } cout << x[i].second + 1;
		}
		cout << endl;
	}
}