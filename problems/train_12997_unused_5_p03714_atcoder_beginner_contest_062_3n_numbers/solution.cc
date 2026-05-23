#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define REP(i, n) for(int i=0;i<(n);++i)
typedef long long ll;

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n; cin >> n;
	vector<ll> a(300000);
	REP(i, 3*n) cin >> a[i];

	priority_queue<ll, vector<ll>, greater<ll>> left;
	priority_queue<ll> right;

	ll lsum = 0; vector<ll> lmax(n+2);
	REP(i, n) lsum += a[i];
	lmax[0] = lsum;
	REP(i, 2*n){
		left.push(a[i]);
		if(i >= n){
			ll tmp = left.top(); left.pop();
			lsum += a[i]; lsum -= tmp;
			lmax[i+1-n] = lsum;
		}
	}

	ll rsum = 0; vector<ll> rmin(n+2);
	for(int i = 3*n-1; i >= 2*n; i--) rsum += a[i];
	rmin[n] = rsum;
	for(int i = 3*n-1; i >= n; i--){
		right.push(a[i]);
		if(i < 2*n){
			ll tmp = right.top(); right.pop();
			rsum += a[i]; rsum -= tmp;
			rmin[i-n] = rsum;
		}
	}

	ll MAX = -1145141919810931;
	REP(i, n+1){
		MAX = max(MAX, lmax[i]-rmin[i]);
	}
	cout << MAX << endl;

	return 0;
}
