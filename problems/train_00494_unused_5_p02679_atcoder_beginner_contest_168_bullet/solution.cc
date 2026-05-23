#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

#define MOD 1000000007

typedef long long ll;

map<pair<ll, ll>, pair<ll, ll> > M;
ll pow2[222222] = { 1 };

ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }

int main(void)
{
	ll n, i, x, y, tmp = -1, cnt = 1;

	scanf("%lld", &n);
	while (n--)
	{
		scanf("%lld %lld", &x, &y);

		if (x == 0 && y == 0)
		{
			++tmp;
			continue;
		}

		if (make_pair(x, y) < make_pair(0LL, 0LL))
			x = -x, y = -y;

		ll GCD = gcd(abs(x), abs(y));
		x /= GCD, y /= GCD;

		if (y > 0)
			M[make_pair(x, y)].first++;
		else
			M[make_pair(-y, x)].second++;
	}

	for (i = 1; i < 222222; i++)
		pow2[i] = pow2[i - 1] * 2 % MOD;

	for (auto p : M)
		cnt = cnt * (pow2[p.second.first] + pow2[p.second.second] - 1LL) % MOD;

	printf("%lld", (tmp + MOD + cnt) % MOD);
	return 0;
}