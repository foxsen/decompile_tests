#include <bits/stdc++.h>
using namespace std;

const int N = (int) 1e5 + 5;

char s[N], t[N];
int q;
int sus[N], sut[N];

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL);
	cin >> s + 1;
	cin >> t + 1;
	int ls = strlen(s + 1), lt = strlen(t + 1);
	for (int i = 1; i <= ls; i++) sus[i] = sus[i - 1] + s[i] - 'A' + 1;
	for (int i = 1; i <= lt; i++) sut[i] = sut[i - 1] + t[i] - 'A' + 1;
	cin >> q;
	while (q--) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		if (abs(sus[b] - sus[a - 1] - (sut[d] - sut[c - 1])) % 3 == 0) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}