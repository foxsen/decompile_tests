#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

int N;
string s;
vector<ll> dp, pp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> s;
    dp = {1};
    for (int i = 0; i < N - 1; i++) {
        pp.assign(dp.size() + 1, 0);
        for (size_t j = 0; j < dp.size(); j++)
            pp[j + 1] = (pp[j] + dp[j]) % MOD;
        dp.assign(dp.size() + 1, 0);
        for (size_t j = 0; j < dp.size(); j++)
            dp[j] = s[i] == '<' ? pp[j] : (pp.back() - pp[j] + MOD) % MOD;
    }
    ll result = 0;
    for (ll x : dp)
        result = (result + x) % MOD;
    cout << result << endl;
}
