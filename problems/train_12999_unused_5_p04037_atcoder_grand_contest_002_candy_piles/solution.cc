#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int n, a[maxn + 3];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	int x = n, y = 1;
	while (x > 1 && y + 1 <= a[x - 1]) {
		x--, y++;
	}
	if (y > a[x - 1]) {
		puts((a[x] - y) & 1 ? "First" : "Second");
	} else {
		int p = (a[x] - y - 1) & 1, z = x - 1;
		while (z > 1 && a[z - 1] == a[z]) z--;
		int q = (x - 1 - z) & 1;
		puts(p && q ? "Second" : "First");
	}
	return 0;
}