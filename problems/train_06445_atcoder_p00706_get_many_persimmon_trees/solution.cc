#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std; int h, w, k, l, m, a, b, s, t, u, v, i, j, x[1000][1000];
int main() {
	while (true) {
		memset(x, 0, sizeof(x)); v = 0;
		cin >> k; if (k == 0) { break; }
		cin >> w >> h;
		for (i = 0; i < k; i++) { cin >> a >> b; x[a][b] = 1; }
		cin >> s >> t;
		for (i = 1; i <= w; i++) {
			for (j = 1; j <= h; j++) {
				u = 0;
				for (l = 0; l < s; l++) {
					for (m = 0; m < t; m++) {
						if (x[i + l][j + m] == 1) {
							u++;
						}
					}
				}
				v = max(v, u);
			}
		}
		cout << v << endl;
	}
}