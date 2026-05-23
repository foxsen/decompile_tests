#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define HERE cout << "HERE: " << __LINE__ << endl;
#define INSP(v) cout << v << " at " << __LINE__ << endl;

using namespace std;
typedef long long ll;

ll dp[101][65536];
int main()
{
    while (1) {
        fill(dp[0], dp[100]+65536, 0);

        int n; cin >> n;
        if (!n) break;
        vector<ll> L(n);
        vector<vector<int>> S, E;
        loop (n, i) {
            int m; cin >> m >> L[i];
            vector<int> s(m), e(m);
            loop (m, j) cin >> s[j] >> e[j];
            S.push_back(s);
            E.push_back(e);
        }

        loop (n, i) {
            int mask = 0;
            loop (S[i].size(), k) {
                for (int l = S[i][k]; l < E[i][k]; l++) {
                    mask ^= (1<<(l-6));
                }
            }
            loop (1<<16, j) {
                dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
                if ((j & mask) == 0) {
                    dp[i+1][j^mask] = max(
                            dp[i+1][j^mask],
                            dp[i][j] + L[i]
                            );
                }
            }
        }

        ll ans = 0;
        loop (1<<16, i) ans = max(ans, dp[n][i]);
        cout << ans << endl;
    }
    return 0;
}