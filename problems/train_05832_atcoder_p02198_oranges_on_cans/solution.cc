#include "bits/stdc++.h"

using namespace std;

using i64 = long long;

const i64 MOD = 1e9+7;

const i64 INF = 1e18+7;


template <typename T = i64>
bool chmax(T& a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}

template <typename T = i64>
bool chmin(T& a, T b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}


signed main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m;
    cin >> n >> m;
    cout << n * m << endl;
}

