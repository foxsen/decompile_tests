#include <bits/stdc++.h>
typedef long long ll; 
 
using namespace std;
 
int main() {
	int N, K;
	cin >> N >> K;
	vector<ll> a(N + 1);
	for (int i = 1; i <= N; ++i) { cin >> a[i]; }
 
	vector<ll> d(N + 1, 0);
	for (int i = 1; i <= N; ++i) { d[i] = d[i - 1] + a[i]; }
 
	vector<ll> v;
	for (int l = 0; l <= N - 1; ++l) {
		for (int r = l + 1; r <= N; ++r) {
			ll x = d[r] - d[l];
			v.push_back(x);
		}
	}

   ll res = 0;
   for (int i = 50; i >= 1; --i) {
	   ll x = res + pow(2, i - 1);
	   int cnt = 0;
	   for (int j = 0; j < v.size(); ++j) {
		   ll y = x & v[j];
		   if (y == x) { ++cnt; }
	   }

	   if (cnt >= K) {
		   res += pow(2, i - 1);
	   }
   }

   cout << res << endl;

   return 0;
}
