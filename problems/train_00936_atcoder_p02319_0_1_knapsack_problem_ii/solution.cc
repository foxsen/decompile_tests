#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, W;
    cin >> N >> W;
    vector<ll> v(N), w(N);
    for (int i = 0; i < N; ++i) {
        cin >> v.at(i) >> w.at(i);
    }

    vector<vector<ll> > dp(N + 1, vector<ll>(10001, INT_MAX));
    dp.at(0).at(0) = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= 10000; ++j) {
            if (j >= v.at(i)) {
                dp.at(i + 1).at(j) = min(dp.at(i).at(j), dp.at(i).at(j - v.at(i)) + w.at(i));
            } else {
                dp.at(i + 1).at(j) = dp.at(i).at(j);
            }
        }
    }

    ll ans = 0;
    for (int j = 0; j <= 10000; ++j) {
        if (dp.at(N).at(j) <= W) ans = j;
    }

    cout << ans << endl;

    return 0;
}
