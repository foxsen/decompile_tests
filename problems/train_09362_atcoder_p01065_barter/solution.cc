#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
#define ALL(c) (c).begin(), (c).end()
#define REP(i,n) for(ll i=0; i < (n); ++i)
#define FOR(i,s,n) for(ll i=s; i < (n); ++i)
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
int main(){
#ifdef _WIN32
	ifstream cin("sample.in");
	ofstream cout("sample.out");
#endif
	cout << fixed << setprecision(8);
	ll n; cin >> n;
	ll x, y; cin >> x >> y;
	vl a(n), b(n), c(n), d(n);
	REP(i, n) cin >> a[i] >> b[i] >> c[i] >> d[i];

	vvvl dp(n+1, vvl(301, vl(1001, -1)));
	dp[0][x][y+350] = 0;
	REP(i, n) REP(j, 301) REP(k, 1001) if(dp[i][j][k]!=-1){
		if (j >= a[i])
			dp[i + 1][j - a[i]][k + b[i]] =
				max(dp[i + 1][j - a[i]][k + b[i]], dp[i][j][k]);
		if (k >= c[i])
			dp[i + 1][j][k - c[i]] =
				max(dp[i + 1][j][k - c[i]], dp[i][j][k] + d[i]);
		dp[i + 1][j][k] = max(dp[i][j][k], dp[i + 1][j][k]);
	}

	ll ma = 0;
	REP(i, 301) FOR(j, 350, 1001) ma = max(ma, dp[n][i][j]);
	
	cout << ma << endl;
}