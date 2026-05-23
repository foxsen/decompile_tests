#include <bits/stdc++.h>
#define Rep(i, x, y) for (int i = x; i <= y; i ++)
#define Dwn(i, x, y) for (int i = x; i >= y; i --)
#define RepE(i, x) for (int i = pos[x]; i; i = g[i].nex)
#define ev g[i].y
#define eps 1e-10
#define fr first
#define sd second
using namespace std;
typedef long long ll;
typedef double db;
const int N = 200005, mod = 1000000007;
int n, m, T, q = 1, ans, a[N], k;
set<int> s;
int main()
{
	scanf ("%d%d", &n, &m);
	Rep(i, 1, n) {
		scanf ("%d", &a[i]);
	}
	a[0] = -1;
	Rep(i, 1, m) {
		s.insert(a[i]);
		if (i > 1) k += (a[i] < a[i - 1]);
	}
	if (k) ans ++;
	else ans += q, q = 0;
	Rep(i, m + 1, n) {
		k += (a[i] < a[i - 1]) - (a[i - m + 1] < a[i - m]);
		// cout << ans<<" "<<*s.begin()<<" "<<*(-- s.end())<<" "<<k<< endl;
		if (*s.begin() != a[i - m] || *(-- s.end()) > a[i]) {
			if (k) ans ++;
			else ans += q, q = 0;
		}
		s.erase(a[i - m]);
		s.insert(a[i]);
	}
	printf("%d\n", ans);
	return 0;
}