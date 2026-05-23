#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr ll MOD = 998244353;

ll power(ll x, ll n){
    x %= MOD;
    ll res = 1;
    while(n > 0){
        if(n&1){
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        n >>= 1;
    }
    return res;
}

ll mod_inv(ll x){
    return power(x, MOD-2);
}

int main(){
    ll n, k, a;
    cin >> n >> k >> a;
    vector<ll> dp(k+n+2,0);  // dp[i] = 得点iになる確率
    dp[0] = 1;
    for(int i=0;i<k;i++){
        ll p = dp[i] * mod_inv(n) % MOD;
        if(i>0) p *= a*mod_inv(100) % MOD;
        p %= MOD;
        dp[i+1] += p;
        dp[i+n+1] += MOD-p;
        if(i>0) dp[i+1] += dp[i];
        dp[i+1] %= MOD;
        dp[i+n+1] %= MOD;
    }
    ll ans = 0;
    for(int i=k;i<=k+n;i++){
        ans += dp[i];
        ans %= MOD;
        dp[i+1] = ((dp[i+1]+dp[i])%MOD+MOD)%MOD;
    }
    cout << ans << endl;
    return 0;
}
