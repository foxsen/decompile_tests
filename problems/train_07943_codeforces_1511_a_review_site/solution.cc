	#include<bits/stdc++.h>
	using namespace std;
	typedef long long ll;
	#define watch(x) cout << (#x) << " = " << x << endl
	#define all(s) s.begin(),s.end()
	#define allr(s) s.rbegin(), s.rend()
	#define sz(s) (int)(s.size())
	#define endl '\n'

	#define Hashim ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);



	int main() {
		Hashim;
		ll t;
		cin >> t;
		while (t--)
		{
			ll n;
			cin >> n;
			vector<int>v(n);

			ll cnt = 0;
			for (int i = 0; i < n; i++)
			{
				cin >> v[i];

				if (v[i] == 1 || v[i] == 3)
					cnt++;

			}
			cout << cnt << endl;


		}


	
		return 0;

	}

	