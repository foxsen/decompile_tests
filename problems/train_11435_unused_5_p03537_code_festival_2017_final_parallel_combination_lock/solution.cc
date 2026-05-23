#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5;

int n, m;
int a[N];
char s[N];

int uf[N];
int find(int x) {
	return uf[x] == x ? x : (uf[x] = find(uf[x]));
}
void unit(int x, int y) {
	x = find(x), y = find(y);
	if (x ^ y) {
		uf[x] = y;
		a[y] += a[x];
	}
}

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	scanf("%d", &m);
	for (int i = 1; i <= n; i++) {
		a[i] = s[i] - 'a';
	}
	for (int i = 1; i <= n + 1; i++) {
		uf[i] = i;
	}
	for (int i = n + 1; i; i--) {
		a[i] -= a[i - 1];
	}
	for (int l = 1, r = n; l + 1 < r; l++, r--) {
		unit(l + 1, r);		
	}
	for (int i = 1, l, r; i <= m; i++) {
		scanf("%d%d", &l, &r);
		unit(l, ++r);
	}
	for (int i = 2; i <= n; i++) {
		if (find(i) == i && (a[i] % 26) && find(i) != find(1) && find(i) != find(n + 1)) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}
