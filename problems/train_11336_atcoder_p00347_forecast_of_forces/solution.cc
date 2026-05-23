#include <bits/stdc++.h>
#define FOR(i, a, b)    for (int i = a; i <= (int) b; ++i)
#define ii              pair <int, int>
using namespace std;
const int N = 1e3 + 3;
int m, n, a[N][N], f[N][N][2], vis[N][N][2];

void init() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
}

int get(int xo, int yo, int xi, int yi) {
    return a[xi][yi] + a[xo - 1][yo - 1] - a[xi][yo - 1] - a[xo - 1][yi];
}

int dp(int i, int j, int id) {
    int &shc = f[i][j][id], &foo = vis[i][j][id];
    if (foo) return shc;
    if (i == m || j == n) return shc = 0;
    shc = INT_MIN; foo = 1;
    if (id == 0) {
        if (i < m && j < n) {
            shc = max(shc, get(i + 1, j + 1, i + 1, n) - dp(i + 1, j, 1));
            shc = max(shc, - get(i + 1, j + 1, m, j + 1) - dp(i, j + 1, 1));
        }
    }
    else {
        if (i < m && j < n) {
            shc = max(shc, - get(i + 1, j + 1, i + 1, n) - dp(i + 1, j, 0));
            shc = max(shc, get(i + 1, j + 1, m, j + 1) - dp(i, j + 1, 0));
        }
    }
    return shc;
}

void solve() {
    cin >> n >> m;
    FOR(i, 1, m) FOR(j, 1, n) {
        int x; cin >> x;
        a[i][j] = a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1] + x;
    }

    cout << abs(dp(0, 0, 0)) << '\n';
}

int main() {
    init(); solve();
}

