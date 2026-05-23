#include <bits/stdc++.h>
using namespace std;
#define int long long   // <-----!!!!!!!!!!!!!!!!!!!

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define printV(v) for(auto&& x : v){cout << x << " ";} cout << endl
#define printVV(vv) for(auto&& v : vv){for(auto&& x : v){cout << x << " ";}cout << endl;}
#define printP(p) cout << p.first << " " << p.second << endl
#define printVP(vp) for(auto&& p : vp) printP(p);

typedef long long ll;
typedef pair<int, int> Pii;
typedef tuple<int, int, int> TUPLE;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<Pii> vp;
const int inf = 1e9;
const int mod = 1e9 + 7;

int H, W;
vector<string> s;
map<vector<string>, int> dp; // 1:ok, -1:ng, 0:unknown
int gx, gy;

// N, E, S, W
const int dx[4] = {-1, 0,  1,  0};
const int dy[4] = { 0, 1,  0, -1};

bool inside(int x, int y) {
    return 0 <= x && x < H && 0 <= y && y < W;
}

vector<string> play(vector<string> s, int i, int j, int k) {
    for ( ; s[i][j] == 'o' && inside(i + dx[k], j + dy[k]); i += dx[k], j += dy[k]) {
        swap(s[i][j], s[i + dx[k]][j + dy[k]]);
    }
    return s;
}

int dfs(vector<string> s) {
    if (dp[s] != 0) return dp[s];

    if (s[gx][gy] == 'o') {
        return dp[s] = 1;
    }

    int ret = -1;
    rep(i, H) {
        rep(j, W) {
            if (s[i][j] == 'o') {
                rep(k, 4) {
                    auto t = play(s, i, j, k);
                    if (dp.count(t) == 0 && dfs(t) == 1) {
                        ret = 1;
                    }
                }
            }
        }
    }
    return dp[s] = ret;

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> H >> W;
    s.resize(H);
    rep(i, H) cin >> s[i];

    int N = 0;
    rep(i, H) {
        rep(j, W) {
            if (s[i][j] == 'o') {
                N++;
            }
            if (s[i][j] == '@') {
                gx = i, gy = j;
                s[i][j] = '.';
            }
        }
    }

    if (H > 1 && W > 1 && N >= 3) {
        cout << "yes" << endl;
        return 0;
    }

    cout << (dfs(s) == 1 ? "yes" : "no") << endl;

}