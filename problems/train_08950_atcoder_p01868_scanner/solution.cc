#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <algorithm>

using namespace std;

#define rep(i,n) for(int (i) = 0;(i) < n;(i)++)
const int INF = 1e9;

int main() {
	int n;
	cin >> n;
	vector<int> t(n);
	rep(i, n) {
		cin >> t[i];
	}
	map<int, map<int, map<int, int>>> dp[51];
	int limit = INF;

	function<int(int, int, int, int)> dfs = [&](int i, int a, int b, int c) {
		if (i == n) {
			return limit = min(limit, max({ a, b, c }));
		}
		int d[3] = { a,b,c };
		sort(d, d + 3);
		a = d[0], b = d[1], c = d[2];
		if (c >= limit)return INF;
		if (dp[i].count(a) && dp[i][a].count(b) && dp[i][a][b].count(c)) {
			return dp[i][a][b][c];
		}

		int ret = dfs(i + 1, a + t[i], b, c);
		ret = min(ret, dfs(i + 1, a, b + t[i], c));
		ret = min(ret, dfs(i + 1, a, b, c + t[i]));
		return dp[i][a][b][c] = ret;
	};

	

	cout << dfs(0, 0, 0, 0) << endl;
}