#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;
const int INF = 1100000000;

int main(){
	ios_base::sync_with_stdio(false);
	int l, n;
	cin >> l >> n;
	vector<int> p(n + 1), d(n), t(n);
	vector<tuple<int, int, int>> warps(n);
	for(int i = 0; i < n; ++i){
		int ip, id, it;
		cin >> ip >> id >> it;
		warps[i] = make_tuple(ip, id, it);
	}
	sort(warps.begin(), warps.end());
	for(int i = 0; i < n; ++i){
		p[i] = get<0>(warps[i]);
		d[i] = get<1>(warps[i]);
		t[i] = get<2>(warps[i]);
	}
	p[n] = l;
	vector<int> dp(n + 1, INF);
	dp[0] = p[0];
	for(int i = 0; i < n; ++i){
		const int x =
			lower_bound(p.begin(), p.end(), p[i] + d[i]) - p.begin();
		if(x <= n){
			const int y = dp[i] + t[i] + (p[x] - (p[i] + d[i]));
			dp[x] = min(dp[x], y);
		}
		if(i <  n){ dp[i + 1] = min(dp[i + 1], dp[i] + p[i + 1] - p[i]); }
	}
	cout << dp[n] << endl;
	return 0;
}
