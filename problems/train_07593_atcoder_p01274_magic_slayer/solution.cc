#include<iostream>
#include<sstream>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cassert>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf = (int)1e9;
const double INF = 1e12, EPS = 1e-9;

const int MX = 100000;
int n, h[100], dp[MX], dp2[MX];
int m, w[100], v[100];
bool single[100];

int main(){
	while(cin >> n, n){
		rep(i, n) cin >> h[i];
		cin >> m;
		rep(i, m){
			string s;
			cin >> s >> w[i] >> s >> v[i];
			single[i] = s == "Single";
		}
		
		rep(i, MX) dp[i] = dp2[i] = inf;
		dp[0] = dp2[0] = 0;
		rep(i, m) if(!single[i]) rep(j, MX){
			int nj = min(MX - 1, j + v[i]);
			dp[nj] = min(dp[nj], dp[j] + w[i]);
		}
		rep(i, m) if(single[i]) rep(j, MX){
			int nj = min(MX - 1, j + v[i]);
			dp2[nj] = min(dp2[nj], dp2[j] + w[i]);
		}
		for(int i = MX - 2; i >= 0; i--) dp2[i] = min(dp2[i], dp2[i + 1]);
		
		ll ans = inf;
		rep(i, MX){
			ll tmp = dp[i];
			rep(j, n) if(h[j] > i) tmp += dp2[h[j] - i];
			ans = min(ans, tmp);
		}
		cout << ans << endl;
	}
	return 0;
}