#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

int N;
int A[20], B[20];
int dp[1<<20][20];
 
signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N;
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    
    rep(S, 1<<N) rep(i, N) dp[S][i] = 10000;
    rep(i, N) dp[1<<i][i] = 0;
    
    for (int S=1; S<(1<<N); S++) {
        int cnt = 0;
        rep(i, N) if ((S>>i)&1) cnt++;
        rep(i, N) {
            if (!((S>>i)&1)) continue;
            int prev;
            if ((cnt-i)%2==0) prev = B[i];
            else prev = A[i];
            int cost = 0;
            for (int j=N-1; j>=0; j--) {
                if ((S>>j)&1) {
                    cost++;
                    continue;
                }
                int now;
                if ((cnt-j)%2==0) now = A[j];
                else now = B[j];
                if (prev>now) continue;
                dp[S|(1<<j)][j] = min(dp[S|(1<<j)][j], dp[S][i]+cost);
            }
        }
    }
    
    int ans = 10000;
    rep(i, N) ans = min(ans, dp[(1<<N)-1][i]);
    if (ans==10000) cout << -1 << endl;
    else cout << ans << endl;
}
