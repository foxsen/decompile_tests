#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()

using ll = long long;
using ld = long double;
using namespace std;

const ll inf = 2e18;
const ll mod = 1e9 + 7;
const ll N = 5e2 + 5;

int n, m, k, a[N][N], b[N][N], init_i, init_j;
ll dp[N][N][20];

ll solve(int i, int j, int moves) {
    if (moves == k / 2) {
        return 0;
    }

    if (dp[i][j][moves] != -1) return dp[i][j][moves];

    ll ans = inf;
    if (j < m) ans = min(ans, solve(i, j + 1, moves + 1) + 2ll * a[i][j]); //moving right
    if (j > 1) ans = min(ans, solve(i, j - 1, moves + 1) + 2ll * a[i][j - 1]); //moving left
    if (i < n) ans = min(ans, solve(i + 1, j, moves + 1) + 2ll * b[i][j]); //moving down
    if (i > 1) ans = min(ans, solve(i - 1, j, moves + 1) + 2ll * b[i - 1][j]); //moving up

    return dp[i][j][moves] = ans;
}

void code() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m - 1; j++) cin >> a[i][j];
    }

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 1; j <= m; j++) cin >> b[i][j];
    }

    if (k & 1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) cout << "-1 "; cout << "\n";
        }

        return;
    }

    for (int i = 0; i <= n + 2; i++) {
        for (int j = 0; j <= m + 2; j++) {
            for (int cnt = 0; cnt < 20; cnt++) dp[i][j][cnt] = -1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) init_i = i, init_j = j, cout << solve(i, j, 0) << " \n"[j == m];
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin>>t;

    while (t-- > 0) {
        code();
    }
}