#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;
ll n, m, s, ans, mn[2005], a[2005];
int main()
{
	ll i, j;
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		scanf ("%lld", &a[i]);
	}
	for (i = 0; i < n; i++) {
		mn[i] = 2e9;
	}
	for (i = 0; i < n; i++) {
		s = i * m;
		for (j = 0; j < n; j++) {
			mn[j] = min(mn[j], a[(i - j + n) % n]);
			s += mn[j];
		}
		if (i == 0 || s < ans) ans = s;
	}
	cout << ans;
    return 0;
}
