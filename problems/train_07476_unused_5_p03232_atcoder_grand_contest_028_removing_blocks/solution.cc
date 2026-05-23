#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll mod = 1e9+7;

ll modpower(ll a, ll r){ //a^r
    ll x = 1;
    while (r > 0) {
        if (r & 1) x = x * a % mod;
        r >>= 1;
        a = a * a % mod;
    }
    return x;
}

ll modinv(ll a){
    return modpower(a, mod-2);
}

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<ll> suminv(N+1, 1);
    for (int i = 2; i <= N; i++) suminv[i] = (suminv[i-1] + modinv(i)) % mod;
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = (ans + (suminv[i] - 1 + suminv[N-i+1]) * A[i-1]) % mod;
    }
    for (int i = 2; i <= N; i++) ans = ans * i % mod;
    cout << ans << endl;
    return 0;
    
}
