#include <bits/stdc++.h>
 
using namespace std;
 
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl;
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}
typedef long long ll;
#define int ll
 
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
template<class S, class T> pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first + t.first, s.second + t.second); }
template<class S, class T> pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first - t.first, s.second - t.second); }
template<class S, class T> ostream& operator<<(ostream& os, pair<S, T> p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
#define X first
#define Y second
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(int)(n);i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = (ll)1e18 + 1;
const long double pi = 3.1415926535897932384626433832795028841971L;
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;
//int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
//int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
vi dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
const ll MOD = 1000000007;
// const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

void solve(int n) {
    vi low(n), high(n);
    rep (i, n) cin >> low[i] >> high[i];

    vector<vll> dp(2 * n + 1, vll(1 << (2 * n), vl(10)));
    rep (j, 10) {
        int ni = 0;
        if (in(j, low[0], high[0] + 1)) ni |= (1 << 1);
        if (j != 0 and in(j, low[0] / 10, high[0] / 10 + 1)) ni |= (1 << 0);
        dp[1][ni][j] = 1;
    }

    for (int i = 1; i < 2 * n; i++) {
        rep (j, 1 << (2 * n)) {
            if (j == 0) continue;
            rep (k, 10) {
                if (dp[i][j][k] == 0) continue;
                rep (nk, 10) {
                    int nj = 0;
                    rep (l, 2 * n) {
                        if ((j & (1 << l)) == 0) continue;
                        if (l % 2 == 0) {
                            int val = k * 10 + nk;
                            if (in(val, low[l / 2], high[l / 2] + 1)) nj |= 1 << (l + 1);
                        }
                        else {
                            if (l != 2 * n - 1) {
                                if (in(nk, low[(l + 1) / 2], high[(l + 1) / 2] + 1)) nj |= 1 << (l + 2);
                                if (nk != 0 and in(nk, low[(l + 1) / 2] / 10, high[(l + 1) / 2] / 10 + 1)) nj |= 1 << (l + 1);
                            }
                        }
                    }
                    dp[i + 1][nj][nk] += dp[i][j][k];
                }
            }
        }
    }

    // rep1 (i, 2 * n) {
    //     rep (j, 1 << (2 * n)) {
    //         rep (k, 10) {
    //             cout << dp[i][j][k] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }

    ll ans = 0;
    rep (i, 2 * n + 1) {
        rep (j, 1 << (2 * n)) {
            if ((j & (1 << (2 * n - 1))) == 0) continue;
            rep (k, 10) {
                ans += dp[i][j][k];
            }
        }
    }
    cout << ans << endl;
}

signed main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) return 0;
        solve(n);
    }
}
