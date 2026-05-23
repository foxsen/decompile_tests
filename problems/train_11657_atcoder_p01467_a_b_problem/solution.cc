#include<iostream>
#include<algorithm>
using namespace std;

#define MAX_N 20

long long a, b, k;
long long c[MAX_N + 1], d[MAX_N + 1], e[MAX_N + 1], bor[MAX_N + 1];
long long p[MAX_N];
long long maxn = 0;

int main() {
	cin >> a >> b >> k;
	p[0] = 1;
	for (int i = 1; i < MAX_N - 1; i++) {
		p[i] = p[i - 1] * 10;
	}
	for (int i = 0; i < MAX_N - 1; i++) {
		c[i] = (a / p[i]) % 10;
		d[i] = (b / p[i]) % 10;
	}
	for (int i = 0; i < (1 << MAX_N); i++) {
		int q[MAX_N];
		int sum = 0;
		for (int j = 0; j < MAX_N; j++) {
			q[j] = (i / (1 << j)) % 2;
			sum += q[j];
		}
		if (sum <= k) {
			for (int j = 0; j < MAX_N; j++) {
				if (q[j] == 1) {
					if (c[j] >= d[j]) {
						e[j] = c[j] - d[j];
					}
					else {
						e[j] = c[j] + 10 - d[j];
						bor[j + 1] = 1;
					}
				}
				else {
					if (c[j] - bor[j] >= d[j]) {
						e[j] = c[j] - bor[j] - d[j];
					}
					else {
						e[j] = c[j] - bor[j] +10 - d[j];
						bor[j + 1] = 1;
					}
				}
			}
			long long res = 0;
			for (int j = 0; j < MAX_N - 1; j++) {
				res += e[j] * p[j];
			}
			maxn = max(maxn, res);
		}
	}
	cout << maxn << endl;
	return 0;
}