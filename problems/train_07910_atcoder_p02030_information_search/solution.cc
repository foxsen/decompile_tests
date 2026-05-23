//include
//------------------------------------------
#include <bits/stdc++.h>
using namespace std;

//typedef
//------------------------------------------
typedef long long LL;
typedef vector<LL> VL;
typedef vector<VL> VVL;
typedef vector<string> VS;
typedef pair<LL, LL> PLL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const int MOD = 1000000007;

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

//main code

int main(int argc, char const* argv[])
{
	int n,m;
	cin >> n >> m;
	VL a(n), b(m);
	set<LL> an,o;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		o.insert(a[i]);
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		o.insert(b[i]);
	}
	b.push_back(MOD);
	for (int i = 0; i < n; i++) {
		if (*lower_bound(ALL(b),a[i]) == a[i]) {
			an.insert(a[i]);
		};
	}

	cout << an.size() << " " << o.size() << endl;
	for (auto&& var : an) {
		cout << var << endl;
	}
	for (auto&& var : o) {
		cout << var << endl;
	}
	return 0;
}

