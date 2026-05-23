#include <bits/stdc++.h>
using namespace std;
#define int long long   // <-----!!!!!!!!!!!!!!!!!!!

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rrep2(i,a,b) for (int i=(a)-1;i>=b;i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define printV(v) for(auto x : v){cout << x << " ";} cout << endl
#define printVS(vs) for(auto x : vs){cout << x << endl;}
#define printVV(vv) for(auto v : vv){for(auto&& x : v){cout << x << " ";}cout << endl;}
#define printP(p) cout << p.first << " " << p.second << endl
#define printVP(vp) for(auto p : vp) printP(p);

typedef long long ll;
typedef pair<int, int> Pii;
typedef tuple<int, int, int> TUPLE;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<Pii> vp;
typedef vector<vector<int>> Graph;
const int inf = 1e9;
const int mod = 1e9 + 7;

int H, W;
int sx, sy;
vector<string> s;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool inside(int x, int y) {
    return 0 <= x && x < H && 0 <= y && y < W;
}

vector<vector<int>> bfs() {
    queue<pair<int, int>> que;
    que.emplace(sx, sy);
    vector<vector<int>> d(H, vector<int>(W, inf));
    d[sx][sy] = 0;

    while (!que.empty()) {
        int x, y;
        tie(x, y) = que.front(); que.pop();
        rep(k, 4) {
            int nx = x + dx[k], ny = y + dy[k];
            if (inside(nx, ny) && s[nx][ny] != '#' && d[nx][ny] == inf) {
                d[nx][ny] = d[x][y] + 1;
                que.emplace(nx, ny);
            }
        }
    }

    return d;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> H >> W;
    s.resize(H);
    rep(i, H) cin >> s[i];
    rep(i, H) {
        rep(j, W) {
            if (s[i][j] == '%') {
                sx = i, sy = j;
            }
        }
    }

    auto d = bfs();
    int princess;
    int soldier = inf;
    rep(i, H) {
        rep(j, W) {
            if (s[i][j] == '@') {
                princess = d[i][j];
            }
            if (s[i][j] == '$') {
                soldier = min(soldier, d[i][j]);
            }
        }
    }

    cout << (princess < soldier ? "Yes" : "No") << endl;
}