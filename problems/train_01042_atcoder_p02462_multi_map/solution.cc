#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <numeric>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll inf = 1ll << 60;
const ll mod = (ll)1e9 + 7;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

#define print(s) cout << s;
#define println(s) cout << s << endl;
#define printd(s, f) cout << fixed << setprecision(f) << s << endl;


int main()
{
	ll n;
	cin >> n;

	multimap<string, ll> a;
	for (int i = 0; i < n; i++)
	{
		int q;
		cin >> q;

		string s;


		switch (q)
		{
			case 0:
				cin >> s;

				ll x;
				cin >> x;
				a.emplace(s, x);
				break;

			case 1:
				cin >> s;

				if (a.count(s) > 0)
				{
					auto p = a.equal_range(s);
					for (auto it = p.first; it != p.second; it++)
					{
						println(it->second);
					}
				}
				else
				{
					//println(0);
				}
				break;

			case 2:
				cin >> s;

				if (a.count(s))
				{
					a.erase(s);
				}
				break;

			case 3:
				string l, r;
				cin >> l >> r;

				auto p = a.equal_range(l);
				auto q = a.equal_range(r);
				for (auto it = p.first; it != q.second; it++)
				{
					println(it->first << " " << it->second);
				}
				break;
		}
	}
}



