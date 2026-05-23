#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll M = 1e9 + 7;
ll dp2[256][256][256];
int sz[256];

int dfs(int v, vector<vector<int>>& g, vector<vector<ll>>& dp) {
    if(g[v].size() == 0) {
        dp[v][1] = 1;
        return sz[v] = 1;
    }

    int sum = 1;
    for(auto ch : g[v]) {
        sum += dfs(ch, g, dp);
    }

    vector<vector<ll>> tmp(g[v].size() + 1, vector<ll>(sum));
    tmp[0][0] = 1;
    for(int i = 0; i < (int)g[v].size(); ++i) {
        int ch = g[v][i];
        for(int l = 0; l < sum; ++l) {
            for(int j = 0; j <= l; ++j) {
                for(int k = 1; k <= sz[ch]; ++k) {
                    (tmp[i + 1][l] += (tmp[i][j] * dp[ch][k] % M) * dp2[j][k][l]) %= M;
                }
            }
        }
    }
    for(int i = 0; i < sum; ++i) {
        dp[v][i + 1] = tmp[g[v].size()][i];
    }
    //cout << "v: " << v << ",  (vnum, res) : " << "(" << sum << ", " << res << ")" << endl;
    return sz[v] = sum;
}

int main() {
    for(int i = 0; i < 201; ++i) {
        dp2[i][0][i] = 1;
        dp2[0][i][i] = 1;
    }
    for(int k = 1; k < 201; ++k) {
        for(int i = 1; i < 201; ++i) {
            for(int j = 1; j < 201; ++j) {
                (dp2[i][j][k] += dp2[i - 1][j - 1][k - 1] + dp2[i - 1][j][k - 1] + dp2[i][j - 1][k - 1]) %= M;
            }
        }
    }

    int N;
    cin >> N;
    vector<vector<int>> g(N);
    vector<bool> in(N);
    for(int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        in[b] = true;
    }
    int root = -1;
    for(int i = 0; i < N; ++i) {
        if(!in[i]) {
            root = i;
            break;
        }
    }
    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1));
    dfs(root, g, dp);

    ll res = 0;
    for(int i = 0; i <= N; ++i) {
        (res += dp[root][i]) %= M;
    }
    cout << res << endl;
}
