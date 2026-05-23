#include <bits/stdc++.h>

typedef long long ll;
#define ALL(a) a, a+sizeof(a)/sizeof(a[0])
#define all(a) a.begin(),a.end()
#define MOD 1000000007
using namespace std;
ll gcd(ll n, ll m) {
	if (m == 0) return n;
	return gcd(m, n % m);
}
ll lcm(ll n, ll m) {return m / gcd(n, m) * n;}

int main(void) {
	ll n,ans=0;
	string hoge;
	cin >> n;
	vector<string> p;
	vector<ll> num(3);
	for (ll i = 0; i < n; i++) {
		hoge = "";
		for (ll j = 0; j < 3; j++)
			cin >> num[j];

		sort(all(num));
		for (ll i = 0; i < 3; i++)
			hoge += to_string(num[i]);
		p.push_back(hoge);
	}
	sort(all(p));
	for (ll i = 1; i < n; i++) {
		if (p[i] == p[i - 1])
			ans++;
	}
	cout << ans << endl;
	return 0;
}
