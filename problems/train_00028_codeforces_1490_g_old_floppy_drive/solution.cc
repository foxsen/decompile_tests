#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)
#define DEB(x)	cout << #x << " " << x << endl;
#define DEB_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()
#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

typedef long long int LL;
typedef pair<int, int> PI;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;

void solve() {
	int n, m;
	cin >> n >> m;

	int a[n];
	REP(i, n)
		cin >> a[i];

	// cout << "question " << endl;
	// REP(i, n)
	// 	cout << a[i] << " ";
	// cout << endl;

	LL peak = LONG_MIN;
	LL sum = 0;
	map<LL, int> mp;

	REP (i, n) {
		sum += a[i];
		if (mp.count(sum) == 0 && peak < sum)
			mp[sum] = i+1;
		CHMAX(peak, sum);
	}

	// for (auto x: mp)
	// 	cout << x.first << ": " << x.second << ", ";
	// cout << endl;

	LL offset = sum;

	unordered_map<int, LL> res;

	REP(q, m) {
		int x;
		cin >> x;

		if (res.count(x)) {
			cout << res[x] << " ";
			continue;
		}

		// cout << "x " << x <<  " : ";

		if (peak < x && offset <= 0) {
			// cout << -1 << " inf" <<endl;
			cout << -1 << " ";
			continue;
		}

		// DEB(offset);

		// if (peak >= x) {
		// 	auto it = mp.lower_bound(x);
		// 	// DEB(it->second);
		// 	sec += it->second;

		// 	// cout << sec << endl;
		// 	cout << sec << " ";
		// 	continue;
		// }

		LL k = peak >= x ? 0: (x-peak + offset-1) / offset;
		// cout << "x " << x << " k " << k << endl;
		LL sec = peak >= x? -1: n*k - 1;

		// LL acc = 0;
		LL koff = k*offset;
		// LL now;

		// REP(i, n) {
		// 	acc += a[i];
		// 	now = koff + acc;
		// 	sec++;

		// 	if (now > x) {
		// 		break;
		// 	}

		// 	if (now == x)
		// 		break;
		// }

		LL search = x - koff;
		// DEB(search);
		auto it = mp.lower_bound(search);
		// DEB(it->second);
		sec += it->second;

		cout << sec << " ";

		res[x] = sec;
	}

	cout << endl;

}

int main() {

	IOS

	int t;
	cin >> t;

	while (t--) {
	    solve();
	}

	return 0;
}


/*
question 
2 0 
x 1 : -1
x 2 : 0


question 
2 -1 
x 2 : 0
x 1 : -2




1
3 3
1 2 4
3 1 2


3
3 3
1 2 4
3 1 2

2 2
2 0
1 2

2 2
2 -1
2 1


*/