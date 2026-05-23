#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(int argc, char const *argv[])
{
	int n, d, a; cin >> n >> d >> a;
	vector<pair<int, int>> v(n);
	rep(i, n) {
		int x, h; cin >> x >> h;
		v[i] = make_pair(x, h);
	}
	sort(v.begin(), v.end());

	ll ans = 0;
	ll sum = 0;
	queue<pair<ll, ll>> que; // <x, damage>
	rep(i, n) {
		ll x = v[i].first, h = v[i].second;
		while(not que.empty() and que.front().first < x) {
			sum -= que.front().second;
			que.pop();
		}
		h -= sum;
		if (h <= 0) continue;
		int time = (h + a - 1) / a;
		ans += time;
		sum += a * time;
		que.push(make_pair(x + 2 * d, a * time));
	}

	cout << ans << endl;
	return 0;
}
