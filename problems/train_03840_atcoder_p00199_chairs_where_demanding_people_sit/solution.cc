#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;

char s[200], a[2];
int main() {
	bool b;
	int n, m;
	while (scanf("%d%d", &n, &m), n) {
		memset(s, 0, sizeof(s)); rep(i, n)s[i] = '#';
		rep(i, m) {
			scanf("%s", a);
			switch (a[0]) {
			case 'A':
				rep(i, n) { if (s[i] == '#') { s[i] = 'A'; break; } }
				break;
			case 'B':
				b = false;
				for (int i = n - 1; i >= 0; i--) {
					if (s[i] == '#' && (!i || s[i - 1] != 'A') && (i + 1 >= n || s[i + 1] != 'A')) {
						b = true; s[i] = 'B'; break;
					}
				}
				if (!b)rep(i, n) { if (s[i] == '#') { s[i] = 'B'; break; } }
				break;
			case 'C':
				b = false;
				rep(i, n) {
					if (s[i] != '#') {
						if (i + 1 < n&&s[i + 1] == '#') { s[i + 1] = 'C'; b = true; break; }
						if (i&&s[i - 1] == '#') { s[i - 1] = 'C'; b = true; break; }
					}
				}
				if (!b)s[n / 2] = 'C';
				break;
			case 'D':
				int k, Max = -1;
				rep(i, n) {
					if (s[i] != '#')continue;
					int cnt = INT_MAX;
					int t = i - 1;
					for (; t >= 0 && s[t] == '#'; t--);
					cnt = t == -1 ? INT_MAX : i - t;
					t = i + 1;
					for (; t < n&&s[t] == '#'; t++);
					cnt = min(cnt, t == n ? INT_MAX : t - i);
					if (Max < cnt) {
						k = i; Max = cnt;
					}
				}
				s[k] = 'D';
				break;
			}
		}
		printf("%s\n", s);
	}
}