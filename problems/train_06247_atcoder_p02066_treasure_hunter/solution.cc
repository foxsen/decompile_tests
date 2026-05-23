#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧  
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|     
　　　 /　　 /￣￣￣￣/　　|  
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿  
　 　　　＼/＿＿＿＿/　（u　⊃  
---------------------------------------------------------------------------------------------------*/






int N, W;
ll P[101];
vector<pair<int, int>> E[101];
pair<int, int> MA[101];
//---------------------------------------------------------------------------------------------------
ll ans = 0;
vector<ll> dfs(int cu, int pa, vector<ll> dp) {
	vector<ll> xs(W + 1, 0); // 連結でない
	vector<ll> xf = dp; // 連結である

	if (dp[W] == 0) {
		if (0 <= MA[cu].first) {
			auto zf = dfs(MA[cu].first, cu, xf);

			rrep(w, W, 0) {
				if (w + MA[cu].second <= W) chmax(xf[w + MA[cu].second], zf[w]);
			}
		}

		fore(p, E[cu]) if (p.first != pa and p.first != MA[cu].first) {
			dfs(p.first, cu, xs);

			vector<ll> zf;
			zf = dfs(p.first, cu, xf);

			rrep(w, W, 0) {
				if (w + p.second <= W) chmax(xf[w + p.second], zf[w]);
			}
		}
		rrep(w, W, 0) xf[w] += P[cu];
		rep(w, 0, W + 1) chmax(ans, xf[w]);
	}
	else {
		fore(p, E[cu]) if (p.first != pa) {
			vector<ll> zf;
			zf = dfs(p.first, cu, xf);

			rrep(w, W, 0) {
				if (w + p.second <= W) chmax(xf[w + p.second], zf[w]);
			}
		}
		rrep(w, W, 0) xf[w] += P[cu];
	}

	return xf;
}
//---------------------------------------------------------------------------------------------------
int dfs2(int cu, int pa) {
	int cnt = 1;

	int to = -1, cst = -1, ma = -1;
	fore(p, E[cu]) if(p.first != pa){
		int c = dfs2(p.first, cu);
		if (ma < c) {
			ma = c;
			to = p.first;
			cst = p.second;
		}
		cnt += c;
	}
	MA[cu].first = to;
	MA[cu].second = cst;

	return cnt;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> W;
	rep(i, 0, N) cin >> P[i];
	rep(i, 0, N - 1) {
		int a, b, c; cin >> a >> b >> c;
		a--; b--;
		E[a].push_back({ b,c });
		E[b].push_back({ a,c });
	}

	dfs2(0, -1);

	vector<ll> dp(W + 1, 0);
	dfs(0, -1, dp);

	cout << ans << endl;
}


