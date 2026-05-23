#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;

ll a, n;
ll ans;
const ll INF = (ll)1e13;

ll mult(ll x, ll y)
{
	if ((double)x * y > 2 * INF) return INF;
	return min(INF, x * y);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> n >> a;
	ans = n;
	for (int k = 2; k <= 40; k++)
	{
		ll x = 2;
		while(true)
		{
			ll y = 1;
			for (int i = 0; i < k; i++)
				y = mult(y, x);
			if (y >= n) break;
			x++;
		}
		x--;
		ll res = a * (k - 1) + k * x;
		ll z = 1;
		for (int i = 0; i < k; i++)
			z *= x;
		for (int i = 0; z < n; i++)
		{
			res++;
			z /= x;
			z *= x + 1;
		}
		ans = min(ans, res);
	}
	cout << ans << endl;

	return 0;
}