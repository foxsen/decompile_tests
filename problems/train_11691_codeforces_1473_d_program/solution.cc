

#include <iostream>
#include <queue>
#include <assert.h>   
#include <vector>
#include <algorithm>
#include <time.h>
#include <numeric>
#include <string>
#include <cstring>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <numeric>
#include <deque>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <array>
#include <cmath>
#include <cstdio>
using namespace std;


//#define double long double
//#define int long long
//#define int unsigned long long

#define ll long long
#define ld long double 
#define pi pair<int, int> 
#define pl pair<ll,ll>  
#define pd pair<ld,ld> 
#define str string  
#define mp make_pair
#define vi vector<int> 
#define vl vector<ll> 
#define vd vector<ld> 
#define vs vector<str> 
#define vpi vector<pi> 
#define vpl vector<pl> 
#define vpd vector<pd> 
#define si set<int> 
#define FF(i,j,n) for(signed i=j;i<=n;i++)  
#define DD(i,j,n) for(signed i=j;i>=n;i--) 
#define F(i,j,n) for(signed i=j;i<n;i++)   
#define D(i,j,n) for(signed i=j;i>n;i--) 
#define mem(a,b) memset(a,b,sizeof(a))
#define ndl cout << endl
#define pte(x) cout << (x) << endl
#define pts(x) cout << (x) << " "
#define ull unsigned long long 

const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;


#define sz(x) (signed)x.size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend() 
#define rsz resize
#define ins insert 
#define ft front() 
#define bk back() 
#define X first
#define Y second
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define lb lower_bound 
#define ub upper_bound 
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define SHOWVECTOR(v) {std::cerr << #v << "\t: ";for(const auto& xxx : v){std::cerr << xxx << " ";}std::cerr << "\n";}
#define SHOWVECTOR2(v) {std::cerr << #v << "\t:\n";for(const auto& xxx : v){for(const auto& yyy : xxx){std::cerr << yyy << " ";}std::cerr << "\n";}}
#define SHOWQUEUE(a) {auto tmp(a);std::cerr << #a << "\t: ";while(!tmp.empty()){std::cerr << tmp.front() << " ";tmp.pop();}std::cerr << "\n";}
#define SHOWSTACK(a) {auto tmp(a);std::cerr << #a << "\t: ";while(!tmp.empty()){std::cerr << tmp.top() << " ";tmp.pop();}std::cerr << "\n";}
//math

const int mod = 1e9 + 7;

ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
int pct(int x) { return __builtin_popcount(x); } 
int bit(int x) { return 31-__builtin_clz(x); } // floor(log2(x)) 
int cdiv(int a, int b) { return a/b+!(a<0||a%b == 0); } // division of a by b rounded up, assumes b > 0 



void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
  cerr << to_string(h); if (sizeof...(t)) cerr << ", ";
  DBG(t...); }
#ifdef LOCAL 
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#define HERE cout << "==========GOTHERE==========" << endl
#else
#define dbg(...) 42
#define HERE 42
#endif


 /* ============== END OF HEADER ============== */





const int maxn = 1e5*3+20;

int n,_,q,k;

void solve(){
	cin >> _;
	while(_--){
		cin >> n >> q;
		str s; cin >> s;
		s = '?' + s;
		vi val(n+1);
		vi mn[2] = {vi(n+2,0), vi(n+2,0)};
		vi mx[2] = {vi(n+2,0), vi(n+2,0)};
		FF(i,1,n){
			if(s[i] == '+') val[i] = val[i-1] + 1;
			else val[i] = val[i-1] - 1;
		}
		FF(i,1,n){
			mn[0][i] = min(mn[0][i-1],  val[i]);
			mx[0][i] = max(mx[0][i-1], val[i]);
		}
		mn[1][n] = val[n];
		mx[1][n] = val[n];
		DD(i,n-1,1){
			mn[1][i] = min(mn[1][i+1], val[i]);
			mx[1][i] = max(mx[1][i+1], val[i]);
		}

		while(q--){
			int l,r; cin >> l >> r;
			if(r == n){
				pte(mx[0][l-1] - mn[0][l-1] + 1);
				continue;
			}
			int delta = val[r] - val[l-1];
			int mnv = min(mn[0][l-1], mn[1][r+1] - delta);
			int mxv = max(mx[0][l-1], mx[1][r+1] - delta);
			dbg(mnv, mxv);

			pte(mxv - mnv + 1);
		}


	}
}

signed main(){
  //clock_t t1 = clock();  
	IOS
	solve();
  
  //cout << "THE ALGORITHM TOOK: " << (clock() - t1) * 1.0 / CLOCKS_PER_SEC * 1000 << "ms"<< endl;
	return 0;
}