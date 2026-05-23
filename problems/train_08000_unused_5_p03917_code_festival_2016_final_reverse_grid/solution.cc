#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, w[110][110], CX[110], CY[110];
char p[210][210], q[4];
long long res = 1, Mod = 1000000007;
int main() {
	int i, j;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%s", p[i] + 1);
	}
	if (n % 2 == 1) {
		for (i = 1; i <= m / 2; i++) {
			if (p[n / 2 + 1][i] != p[n / 2 + 1][m + 1 - i]) {
				res = res * 2 % Mod;
				break;
			}
		}
	}
	if (m % 2 == 1) {
		for (i = 1; i <= n / 2; i++) {
			if (p[i][m / 2 + 1] != p[n + 1 - i][m / 2 + 1]) {
				res = res * 2 % Mod;
				break;
			}
		}
	}
	for (i = 1; i <= n / 2; i++) {
		for (j = 1; j <= m / 2; j++) {
			q[0] = p[i][j];
			q[1] = p[n + 1 - i][j];
			q[2] = p[i][m + 1 - j];
			q[3] = p[n + 1 - i][m + 1 - j];
			sort(q, q + 4);
			int s = 0;
			do {
				s++;
			} while (next_permutation(q, q + 4));
			w[i][j] = s;
			if (s == 24) {
				CX[i] = 1, CY[j] = 1;
				res = res * 12 % Mod;
			}
			else res = res*s%Mod;
		}
	}
	int c = 0;
	for (i = 1; i <= 100; i++)c += CX[i] + CY[i];
	if (c > 0)c--;
	for (i = 0; i < c; i++)res = res * 2 % Mod;
	printf("%lld\n", res);
	return 0;
}