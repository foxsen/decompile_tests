#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, pii> pip;
const ll INF = 1e9+100;
const ll MOD = 1e9+7;
const double EPS  = 1e-10;
const bool debug = 0;
//---------------------------//

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll to_ll(string s) {
	ll res;
	stringstream ss(s);
	ss >> res;
	return res;
}

string s;

int main(){
	cin >> s;
	
	int lp = s.size();
	if (s.find('(') != string::npos) lp = s.find('(');
	
	int pc = s.find('.');
	ll q = 1;
	while (pc + 1 < lp) { // .1( -> 1.(
		q *= 10;
		swap(s[pc], s[pc + 1]);
		pc++;
	}
	
	ll u, d;
	if (s.find('(') == string::npos) {
		string str = s.substr(0, pc);
		u = to_ll(str);
		d = q;
	}
	else {
		string B = s.substr(lp + 1, s.size() - 2 - lp);
		ll b = to_ll(B);
		ll a = to_ll(s.substr(0, pc));
		
		u = a * (ll)pow(10, B.size()) + b - a;
		d = q * (ll)pow(10, B.size()) - q;
	}
	
	ll g = gcd(u, d);
	u /= g; d /= g;
	printf("%lld/%lld\n", u, d);
	
	return 0;
}