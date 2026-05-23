#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;
typedef long long LL;
const int N = 3e5 + 10, mod = 998244353;
string g[N];
int dp[N];

int fastPow(int a, int k) {
    int res = 1;
    while (k) {
        if (k & 1) res = (LL)res * a % mod;
        k >>= 1;
        a = (LL)a * a % mod;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    int n, m, sum = 0, res = 0;
    n = 300000;
    for (int i = 2; i <= n; i++) {
        if (i & 1) sum = (sum + 1) % mod;
        dp[i] = ((LL)dp[i - 1] * 2 % mod + sum + !(i & 1)) % mod;
        sum = (sum << 1) % mod;
    }
    sum = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> g[i];
        for (auto c : g[i])
            if (c == 'o') sum++;
    }
    for (int i = 0; i < n; i++) {
        int cnt = 0, len = 0;
        while (cnt <= m) {
            if (cnt == m || g[i][cnt] == '*') {
                if (len) {
                    res = (res + (LL)dp[len] *
                                     fastPow(2, sum - len) % mod) %
                          mod;
                    len = 0;
                }
            } else {
                len++;
            }
            cnt++;
        }
    }
    for (int i = 0; i < m; i++) {
        int cnt = 0, len = 0;
        while (cnt <= n) {
            if (cnt == n || g[cnt][i] == '*') {
                if (len) {
                    res = (res + (LL)dp[len] *
                                     fastPow(2, sum - len) % mod) %
                          mod;
                    len = 0;
                }
            } else {
                len++;
            }
            cnt++;
        }
    }
    cout << res << endl;
    return 0;
}