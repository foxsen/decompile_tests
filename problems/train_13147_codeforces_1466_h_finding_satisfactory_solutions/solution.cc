#include <bits/stdc++.h>
using namespace std;

const int maxn = 41, P = 1000000007;
int n, p[maxn], base[maxn], f[5100];
int fact[maxn], C[maxn][maxn], pw[maxn][maxn], vis[maxn];
vector<int> len, cnt, sub[5100];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]), p[i]--;
    }
    auto init = [&]() {
        vector<int> V;
        for (int i = 0; i < n; i++) if (!vis[i]) {
            int len = 0;
            for (int j = i; !vis[j]; j = p[j]) vis[j] = 1, len++;
            V.push_back(len);
        }
        sort(V.begin(), V.end());
        for (int i = 0, j; i < V.size(); i = j) {
            for (j = i; j < V.size() && V[i] == V[j]; j++);
            len.push_back(V[i]), cnt.push_back(j - i);
        }
        for (int i = base[0] = 1; i <= len.size(); i++) {
            base[i] = base[i - 1] * (cnt[i - 1] + 1);
        }
        for (int i = fact[0] = C[0][0] = 1; i <= n; i++) {
            fact[i] = 1LL * i * fact[i - 1] % P;
            for (int j = C[i][0] = 1; j <= i; j++) {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
            }
        }
        for (int S = 0; S < base[len.size()]; S++) {
            function<void(int, int)> dfs = [&](int pos, int T) {
                if (pos == len.size()) {
                    if (T) sub[S].push_back(T); return;
                }
                for (int i = 0; i <= S / base[pos] % (cnt[pos] + 1); i++) {
                    dfs(pos + 1, T + i * base[pos]);
                }
            };
            dfs(0, 0);
        }
    };
    auto solve = [&]() {
        for (int i = 0; i < n; i++) {
            pw[i][0] = 1;
            for (int j = 0; j <= i; j++) {
                pw[i][1] = (pw[i][1] + 1LL * C[i][j] * fact[j] % P * fact[n - j - 1]) % P;
            }
            for (int j = 2; j <= n; j++) {
                pw[i][j] = 1LL * pw[i][j - 1] * pw[i][1] % P;
            }
        }
        for (int S = f[0] = 1; S < base[len.size()]; S++) {
            for (int T : sub[S]) {
                int s1 = 0, s2 = 0, s3 = 0;
                int coef = 1;
                for (int i = 0; i < len.size(); i++) {
                    int x = S / base[i] % (cnt[i] + 1);
                    int y = T / base[i] % (cnt[i] + 1);
                    s1 += len[i] * y, s2 += len[i] * (x - y), s3 += y;
                    coef = 1LL * coef * C[x][y] % P;
                }
                if (!(s3 & 1)) coef = P - coef;
                f[S] = (f[S] + 1LL * pw[s2][s1] * f[S - T] % P * coef) % P;
            }
        }
    };
    init(), solve();
    printf("%d\n", f[base[len.size()] - 1]);
    return 0;
}