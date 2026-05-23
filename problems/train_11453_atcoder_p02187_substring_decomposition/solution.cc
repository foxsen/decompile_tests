#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
#include <bitset>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef pair<ll,ll> P;
typedef vector<P> vpl;
typedef tuple<ll,ll,ll> tapu;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(int i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int MAX = 510000;
ll dy[8] = {0,1,0,-1,1,-1,1,-1};
ll dx[8] = {1,0,-1,0,1,-1,-1,1};
const double pi = acos(-1);
const double eps = 1e-7;
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){
	if(a>b){
		a = b; return true;
	}
	else return false;
}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){
	if(a<b){
		a = b; return true;
	}
	else return false;
}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){cout << a << " " << b << "\n";}
template<typename T1,typename T2,typename T3> inline void print3(T1 a, T2 b, T3 c){
	cout << a << " " << b << " " << c << "\n";
}
const int mod = 1e9 + 7;
//const int mod = 998244353;


struct SuffixArray{
	vector<int> ran;
	vector<int> tmp;
	vector<int> sa;
	vector<int> rsa;
	vector<int> lcp;
	int k=0, n=0;
	string str;

	SuffixArray(string s){
		str = s;
		n = s.size();
		ran.resize(n+1,0);
		tmp.resize(n+1,0);
		sa.resize(n+1,0);
		rsa.resize(n+1,0);
		lcp.resize(n+1,0);
		build();
		calcLCP();
	}

	struct CompareSA {
        int n, k;
        const vector<int> &rank;
        CompareSA(int n, int k, const vector<int> &rank_sa) : n(n), k(k), rank(rank_sa) {}
        bool operator()(int i, int j) {
            if (rank[i] != rank[j]) return (rank[i] < rank[j]);
            else {
                int rank_ik = (i + k <= n ? rank[i + k] : -1);
                int rank_jk = (j + k <= n ? rank[j + k] : -1);
                return (rank_ik < rank_jk);
            }
        }
    };

	void build(){
		for(int i=0; i<=n; i++){
			sa[i] = i;
			ran[i] = i < n ? str[i] : -1;
		}
		for(k=1; k<=n; k*=2){
			CompareSA csa(n, k, ran);
			sort(sa.begin(),sa.end(),csa);
			tmp[sa[0]] = 0;
			for(int i=1; i<=n; i++){
				tmp[sa[i]] = tmp[sa[i-1]] + (csa(sa[i-1], sa[i]) ? 1 : 0);
			}
			for(int i=0; i<=n; i++){
				ran[i] = tmp[i];
			}
		}
	}

	bool contain(string t){
		int a = 0, b = str.size();
		while(b - a > 1){
			int c = (a+b) / 2;
			if(str.compare(sa[c], t.size(), t) < 0) a = c;
			else b = c;
		}
		return str.compare(sa[b], t.size(), t) == 0;
	}

	void calcLCP(){
		for(int i=0; i<=n; i++) rsa[sa[i]] = i;
		lcp[0] = 0;
		int cur = 0;
		for(int i=0; i<=n; i++){
			int pi = sa[rsa[i] - 1];
			if(cur > 0) cur--;
			for(; pi + cur < n && i + cur < n; cur++){
				if(str[pi + cur] != str[i + cur]) break;
			}
			lcp[rsa[i] - 1] = cur;
		}
	}
};

int main(){
	string s,t; cin >> s >> t;
	ll k; cin >> k;
	ll n = s.size();
	s += '#' + t;
	SuffixArray sa(s);
	ll m = s.size();
	ll T = 0;
	ll fin = -1;
	vl v(n+2,0);
	rep(i,m){
		if(sa.sa[i] > n){
			ll now = inf;
			for(ll j=i-1; j>fin; j--){
				chmin(now,sa.lcp[j]);
				if(now < k) break;
				if(sa.sa[j] < n) chmax(v[sa.sa[j]],now);
			}
			fin = i;
			now = sa.lcp[i];
			for(ll j=i+1; j<=m; j++){
				if(sa.sa[j] >= n) break;
				if(now < k) break;
				chmax(v[sa.sa[j]],now);
				chmin(now,sa.lcp[j]);
			}
		}
	}
	vl dp(n+2,0);
	rep(i,n+2){
		if(i>0) dp[i] += dp[i-1];
		if(!v[i]) continue;
		if(i>0 && !dp[i]) continue;
		dp[i+k]++;
		dp[i+v[i]+1]--;
	}
	if(dp[n]) puts("Yes");
	else puts("No");
}
