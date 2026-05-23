#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define MOD 1000000007
#define maxn 100010

void solve() {
    int n, t;
    cin >> n >> t;

    vector<int> v(t + 2);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        v[a] += 1, v[b] += -1;
    }
    int sum = 0, mx = 0;
    for (int i = 0; i <= t; i++) {
        sum += v[i];
        mx = max(mx, sum);
    }
    cout << mx << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
//    cin >> t;

    while (t--)
        solve();
    return 0;
}
