#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

#define alpha ios::sync_with_stdio(0); cin.tie(0);

const int B = 130000;
int w[2][2*B+5], s[2][2*B+5], ans[505];

void solve() {
	int n, MOD; cin >> n >> MOD;

	w[0][B] = s[0][B] = 1;
	for(int i=B; i<=2*B; i++) s[0][i] = 1;

	for(int i=1; i<=n; i++) {
		int curs=1, I=i&1, J=I^1;
		memset(w[I], 0, sizeof(w[I])), memset(s[I], 0, sizeof(s[I]));
		int u=i*(i-1)/2;
		for(int j=-u+B; j<=u+B; j++) {
			w[I][j]=curs;
			curs=(0ll + curs-s[J][j]+s[J][j-i]+s[J][j+i]-s[J][j]+2ll*MOD) % MOD;
		}
		for(int j=B-i*(i-1)/2, v=(i+2)*(i+1)/2+B; j<=v; j++) {
			s[I][j] = (s[I][j-1] + w[I][j])%MOD;
		}
		for(int j=1; j<i; j++) {
			ans[i] = (ans[i] + 1ll*(s[J][(i+1)*i/2+B]-s[J][j+B]+MOD)%MOD*(i-j))%MOD;
		}
	}

	for(int i=2; i<=n; i++) {
		ans[i] = (ans[i] + 1ll*i*ans[i-1]) % MOD;
	}

	cout << ans[n];
	
}




int main(int argc, char const *argv[])
{	
	alpha;
	#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout); 
	#endif

	int t=1;
	// cin >> t;

	while(t--) {
		solve();
		cout << '\n';
	}
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;
}