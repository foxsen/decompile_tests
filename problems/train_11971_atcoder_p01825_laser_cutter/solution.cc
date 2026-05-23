#include <bits/stdc++.h>
 
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

template<class D>
struct Hungarian {
    V<D> le, ri;
    V<int> perm;

    Hungarian(const VV<D> &c) {
        int n = int(c.size()), m = int(c[0].size());
        assert(n <= m);
        le = V<D>(n, D(0)); ri = V<D>(m, D(0));
        perm = V<int>(n);
        V<int> to_r(n, -1), to_l(m, -1);

        auto cost = [&](int l, int r) { return c[l][r] + le[l] + ri[r]; };
        for (int l = 0; l < n; l++) {
            V<bool> l_u(n), r_u(m);
            V<int> tr(m, -1), min_l(m, l);
            l_u[l] = true;
            V<D> cost_buf(m);
            for (int j = 0; j < m; j++) cost_buf[j] = cost(l, j);
            while (true) {
                int b = -1;
                D d = numeric_limits<D>::max();
                for (int j = 0; j < m; j++) {
                    assert(abs(cost_buf[j] - cost(min_l[j], j)) <= 1e-9);
                    if (!r_u[j] && cost(min_l[j], j) < d) {
                        b = j;
                        d = cost(min_l[j], j);
                    }
                }
                for (int i = 0; i < n; i++) if (l_u[i]) le[i] -= d;
                for (int j = 0; j < m; j++) {
                    if (r_u[j]) ri[j] += d;
                    else cost_buf[j] -= d;
                }
                tr[b] = min_l[b];
                int c = to_l[b];
                if (c == -1) {
                    while (b != -1) {
                        int a = tr[b], z = to_r[a];
                        to_l[b] = a;
                        to_r[a] = b;
                        b = z;
                    }
                    break;
                }
                l_u[c] = r_u[b] = true;
                for (int j = 0; j < m; j++) {
                    if (cost(c, j) < cost(min_l[j], j)) {
                        min_l[j] = c;
                        cost_buf[j] = cost(c, j);
                    }
                }
            }
        }
        perm = to_r;
    }    
};

 
using D = double;
const D PI = acos(D(-1)), EPS = 1e-10;
using P = complex<D>;
 
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;
 
    D ans = 0;
 
    int n;
    cin >> n;
    V<P> up(n), dw(n);
    D x, y;
    cin >> x >> y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y; up[i] = P(x, y);
        cin >> x >> y; dw[i] = P(x, y);
        ans += abs(up[i]-dw[i]);
    }
 
    int l = int(up.size()), r = int(dw.size());
    VV<D> cost(l, V<D>(r));
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < r; j++) {
            cost[i][j] = abs(up[i] - dw[j]);
        }
    }
    auto perm = Hungarian<D>(cost).perm;
    for (int i = 0; i < l; i++) {
        ans += cost[i][perm[i]];
    }
    cout << ans << endl;
    return 0;
}

