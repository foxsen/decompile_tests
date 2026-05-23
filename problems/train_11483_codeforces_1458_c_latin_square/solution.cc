#include <bits/stdc++.h>
using namespace std;
#define pb  push_back
#define ll  long long
#define vi  vector<ll >
#define vvi vector<vi >
#define all(x) x.begin(), x.end()

int n, q;
vvi v, w;
vi  e, p;
string s;

void add(ll& x, ll y) {
    x = (x + y + n) % n;
}

void f() {
    cin >> n >> q;
    v.assign(n, vi(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> v[i][j]; --v[i][j];
        }
    cin >> s;
    e = {0, 0, 0};
    p = {0, 1, 2};
    for (int i = 0; i < q; ++i) {
        char c = s[i];
        if (c == 'R') add(e[p[1]],  1);
        if (c == 'L') add(e[p[1]], -1);
        if (c == 'D') add(e[p[0]],  1);
        if (c == 'U') add(e[p[0]], -1);
        if (c == 'I') swap(p[1], p[2]);
        if (c == 'C') swap(p[0], p[2]);
    }
    w = v;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            vi z = {i, j, v[i][j]};
            int I = z[p[0]] + e[p[0]];
            int J = z[p[1]] + e[p[1]];
            int K = z[p[2]] + e[p[2]];
            w[I % n][J % n] = K % n + 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << w[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while (t--)
        f();

    return 0;
}