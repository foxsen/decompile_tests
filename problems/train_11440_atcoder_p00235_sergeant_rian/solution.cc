#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int field[21][21];

int getFarthest(int p) {
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (field[p][i]) {
			field[i][p] = 0;
			res = max(res, field[p][i] + getFarthest(i));
		}
	}
	return res;
}

int main () {
	while (cin >> n, n) {
		int dim[n + 1];
		int sum_2t = 0;
		memset(dim, 0, sizeof(dim));
		memset(field, 0, sizeof(field));
		for (int i = 0; i < n - 1; i++) {
			int a, b, t;
			cin >> a >> b >> t;
			field[a][b] = field[b][a] = t;
			dim[a]++; dim[b]++;
			sum_2t += 2 * t;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if ((dim[i] == 1 || dim[j] == 1) && !(i == 1 && dim[i] == 1) && !(j == 1 && dim[j] == 1)) {
					sum_2t -= field[i][j];
					field[i][j] = 0;
				}
			}
		}
		cout << sum_2t - getFarthest(1) << endl;
	}
	return 0;
}