#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue> 
#include <stack>
#include <set>

using namespace std;
typedef long long ll;
#define rep(i, s, e) for (int(i) = (s); (i) <= (e); ++(i))
#define all(x) x.begin(),x.end()


int main()
{
	int n, q; cin >> n >> q;
	vector<ll> a(n);
	rep(i, 0, n - 1)cin >> a[i];
	
	rep(_, 1, q)
	{
		ll x; cin >> x;
		ll ans = 0;
		ll sum = 0;
		int right = 0;
		rep(left, 0, n - 1)
		{
			while (right < n && sum + a[right] <= x)
			{
				sum += a[right];
				++right;
			}
			ans += right - left;

			sum -= a[left];
		}
		cout << ans << endl;
	}
}
