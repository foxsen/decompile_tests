#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define  debug(x) cerr<<#x<<" "<<x<<"\n";
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
bool solve()
{
	int n, k1, k2, w, b; cin >> n >> k1 >> k2 >> w >> b;
	if (k1 + k2 >= 2 * w and (n - k1) + (n - k2) >= 2 * b)return true;
	return false;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	//t=1;
	while (t--)
	{
		if (solve())cout << "YES\n";
		else cout << "NO\n";

	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}