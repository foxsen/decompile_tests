#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <random>
#include <chrono>
typedef long long ll;
typedef long double ld;
using namespace std;

class segment
{
public:
	int l, r;
	segment(int _l = 0, int _r = 0) : l(_l), r(_r) {}
};
bool cmp(segment& a, segment& b)
{
	return a.l + a.r < b.l + b.r;
}
int overlap(segment a, segment b)
{
	if (a.r < b.l || b.r < a.l) return 0;
	return min(a.r, b.r) - max(a.l, b.l) + 1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<segment>v(m);
	for (int i = 0; i < m; i++)
	{
		cin >> v[i].l >> v[i].r;
		v[i].l--;
		v[i].r--;
	}
	sort(v.begin(), v.end(), cmp);
	vector<vector<int> > s(m + 1, vector<int>(n, 0));
	// s[i][j] -> prvych kolko ludi berieme a co je zaciatok nasho intervalu
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j + k - 1 < n; j++)
		{
			s[i][j] = s[i - 1][j] + overlap(v[i - 1], segment(j, j + k - 1));
		}
	}
	int ans = 0;
	for (int pf = 0; pf <= m; pf++) // vyskusame, ze ktoremu prefixu ludi bude prvy autor rozpravat
	{
		int ans1 = 0;
		for (int i = 0; i + k - 1 < n; i++) // kde zacne prvy autor rozpravat?
		{
			ans1 = max(ans1, s[pf][i]);
		}
		int ans2 = 0;
		for (int i = 0; i + k - 1 < n; i++) // kde zacne druhy autor rozpravat?
		{
			ans2 = max(ans2, s[m][i] - s[pf][i]);
		}
		ans = max(ans, ans1 + ans2);
	}
	cout << ans << "\n";
	return 0;
}