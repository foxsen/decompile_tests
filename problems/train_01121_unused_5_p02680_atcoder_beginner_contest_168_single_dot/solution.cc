#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define repr(i, n) REPR(i, n, 0)
#define REPR(i, s, e) for(int i=(int)(s-1); i>=(int)(e); i--)
#define pb push_back
#define all(r) r.begin(),r.end()
#define rall(r) r.rbegin(),r.rend()
#define fi first
#define se second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const double EPS = 1e-8;

template<typename T> T chmax(T& a, const T& b){return a = (a > b ? a : b);}
template<typename T> T chmin(T& a, const T& b){return a = (a < b ? a : b);}

template<typename T>
void zaatu(const vector<T>& v, map<T, ll>& mv, vector<T>& rv) {
    for(auto&& i: v) mv[i] = 0;
    rv.resize(mv.size());
    int cnt = 0;
    for(auto& p : mv) {
        rv[cnt] = p.fi;
        p.se = cnt++;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vl a(n), b(n), c(n), d(m), e(m), f(m);
    rep(i, n) cin >> a[i] >> b[i] >> c[i];
    rep(i, m) cin >> d[i] >> e[i] >> f[i];
    const int INF = 1e9+10;
    map<ll, ll> mx, my;
    vl rx, ry;
    mx[0] = 1;
    my[0] = 1;
    mx[-INF] = 1; mx[INF] = 1; mx[-INF-1] = 1; mx[INF+1] = 1;
    my[-INF] = 1; my[INF] = 1; my[-INF-1] = 1; my[INF+1] = 1;
    zaatu(a, mx, rx);
    zaatu(b, mx, rx);
    zaatu(c, my, ry);
    zaatu(d, mx, rx);
    zaatu(e, my, ry);
    zaatu(f, my, ry);
    
    using B = bitset<4>;
    vector<vector<B>> nxt(my.size()-1, vector<B>(mx.size()-1));
    rep(i, nxt.size()) rep(j, nxt[i].size()) nxt[i][j].set();

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};

    rep(i, n) {
        auto y = my[c[i]];
        REP(x, mx[a[i]], mx[b[i]]) {
            nxt[y-1][x].reset(3);
            nxt[y][x].reset(1);
        }
    }
    rep(i, m) {
        auto x = mx[d[i]];
        REP(y, my[e[i]], my[f[i]]) {
            nxt[y][x-1].reset(2);
            nxt[y][x].reset(0);
        }
    }

    const int sx = mx[-INF], tx = mx[INF];
    const int sy = my[-INF], ty = my[INF];

    

    vector<vl> area(my.size()-1, vl(mx.size()-1));
    queue<pii> q;
    q.push({my[0], mx[0]});
    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        int y = p.fi, x = p.se;
        if(area[y][x] != 0) continue;
        if(y == sy || y == ty || x == sx || x == tx) {
            cout << "INF" << '\n';
            return 0; 
        }
        {
            area[y][x] = (ry[y+1] - ry[y]) * (rx[x+1] - rx[x]);
        }
        rep(k, 4) if(nxt[y][x][k]) { 
            int ny = y+dy[k], nx = x+dx[k];
            if(area[ny][nx] == 0) q.push({ny, nx});
        }
    }
    ll ans = 0LL;
    for(auto&& low: area) ans += accumulate(all(low), 0LL);
    cout << ans << '\n';
    return 0;
}