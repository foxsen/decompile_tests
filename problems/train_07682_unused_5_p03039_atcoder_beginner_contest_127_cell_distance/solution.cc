#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#define ll long long
using namespace std;

ll mod_pow(ll n, ll p, ll mod){
    if(p==0) return 1;
    ll res = mod_pow(n*n%mod, p/2, mod);
    if(p%2==1) res = res * n % mod;
    return res;
}

int main(){
    ll N, M, K;
    cin >> N >> M >> K;
    ll mod = 1e9+7;

    vector<ll> fct(N*M-1,1);
    for(ll i=1; i<=N*M-2; i++){
        fct[i] = i * fct[i-1] % mod;
    }

    vector<ll> invfct(N*M-1,1);
    invfct[N*M-2] = mod_pow(fct[N*M-2], mod-2, mod) % mod;
    for(ll i=N*M-3; i>=1; i--){
        invfct[i] = (i+1)*invfct[i+1] % mod;
    }

    ll W = (fct[N*M-2]*invfct[K-2] % mod)*invfct[N*M-K] % mod;

    ll ans = 0;
    for(ll dx=1; dx<M; dx++){
        ll A = (N*N*(M-dx)) % mod;
        ans = (ans + A * dx % mod) % mod;
    }
    for(ll dy=1; dy<N; dy++){
        ll A = (M*M*(N-dy)) % mod;
        ans = (ans + A * dy % mod) % mod;
    }
    cout << (ans*W)%mod << endl;
}
