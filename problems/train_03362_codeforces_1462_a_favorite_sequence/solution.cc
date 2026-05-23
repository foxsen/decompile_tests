#include <bits/stdc++.h>
using namespace std;
 
#define IO          ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int         long long
#define double      long double
#define vi          vector<int>
#define vvi         vector<vi>
#define pii         pair<int, int>
#define vii         vector<pii>
#define endl        '\n'
#define pb          emplace_back
#define all(v)      (v).begin(), (v).end()
#define rall(v)     (v).rbegin(), (v).rend()
#define mod         1000000007
const int N = 2e5;
int b[N];

void solve()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> b[i];
	}
	int d = ceil((double)n/2);
	for(int i=0;i<d;i++)
	{
		if(i == n-1-i)
		{
			cout << b[i] << " ";
		}
		else
		{
			cout << b[i] << " " << b[n-i-1] << " ";
		}
	}
	cout << endl;
}
signed main() {
	IO;
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}
