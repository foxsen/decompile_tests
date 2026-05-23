#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<pi, pi> pp;
typedef pair<ll, ll> pl;
const double EPS = 1e-9;
const ll MOD = 1000000007;
const int inf = 1 << 30;
const ll linf = 1LL << 60;

int n, r;
int p[300000];
bool saw[300001];
vector<int> v;
bool dp[300001];
int d_m = 0;

int main() {
    cin >> n >> r;
    rep(i,n) cin >> p[i];
    rep(i,n) p[i]--;
    rep(i,n) {
        if (saw[i]) continue;
        saw[i] = true;
        int cnt = 1;
        int j = p[i];
        while (true) {
            if (saw[j]) break;
            saw[j] = true;
            j = p[j];
            cnt++;
        }
        v.push_back(cnt);
    }
    sort(v.begin(), v.end());
    dp[0] = true;
    rep(i,v.size()) {
        int con = 1;
        while (i != v.size()-1) {
            if (v[i] == v[i+1]) {
                i++;
                con++;
            } else {
                break;
            }
        }
        for (int k = d_m; k >= 0; k--) {
            if (!dp[k]) continue;
            rep(_,con) {
                dp[k+v[i]*(_+1)] = true;
                d_m = max(d_m, k+v[i]*(_+1));
            }
        }
    }
    if (dp[r]) cout << "Yes" << endl;
    else cout << "No" << endl;
}

