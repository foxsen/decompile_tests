#include <bits/stdc++.h>
#define int long long int
const int INF = 1e9 + 7;
using namespace std;
const int m = 1e9 + 7;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		string a[n], b[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		for (int j = 0; j < n; j++)
		{
			if (a[0][j] != b[0][j])
			{
				for (int i = 0; i < n; i++)
				{
					a[i][j] ^= 1;
				}
			}
		}
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < n; j++)
			{
				if (a[i][j] != b[i][j])
				{
					for (int j = 0; j < n; j++)
						a[i][j] ^= 1;
				}
			}
		}
		bool ans = true;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				if (a[i][j] != b[i][j])
				{
					ans = false;
					break;
				}
			if (ans == false)
				break;
		}
		if (ans)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}