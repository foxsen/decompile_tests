#include<bits/stdc++.h>
//#define int long long
#define ll long long
#define p pair<int, int>
#define endl '\n'
const int INF = 1000000001;

using namespace std;

const int C = 998244353;
vector<ll> fact, minus_fact;

ll pow1(ll x, ll y, ll z=C){
    if (y == 0){
        return 1;
    }
    if (y % 2 == 0){
        return pow1(x*x % z, y/2, z);
    }
    return pow1(x, y-1, z)*x % z;
}

void facts(int n){
    fact = {1}, minus_fact = {1};
    for (int q = 1; q <= n; q++){
        fact.push_back(fact.back()*q % C);
        minus_fact.push_back(minus_fact.back()*pow1(q, C-2) % C);
    }
}

ll c(int k, int n){
    if (k < 0 || k > n){
        return 0;
    }
    return fact[n]*minus_fact[k] % C*minus_fact[n-k] % C;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    facts(200179);
    int n;
    cin >> n;
    vector<p> a(n);
    for (int q = 0; q < n; q++){
        cin >> a[q].first >> a[q].second;
    }
    vector<int> now = {1};
    for (int q = 0; q < n; q++){
        int w3 = (now.size()+a[q].first+a[q].second+1)/2, w4 = now.size()+a[q].first+a[q].second;
        vector<__int128> will(w3-a[q].second, 0);
        vector<ll> cc(now.size()+a[q].first);
        for (int q1 = 0; q1 < cc.size(); q1++){
            cc[q1] = c(q1, a[q].first+a[q].second);
        }
        for (int q1 = a[q].second; q1 < w3; q1++){
            int w = min(q1+1, (int)now.size()), w1 = q1-a[q].second, w2 = max(0, q1-a[q].first-a[q].second);
            for (int q2 = w2; q2 < w; q2++){
                will[w1] += cc[q1-q2]*now[q2];
            }
        }
        now = {};
        for (__int128 q1: will){
            now.push_back(q1 % C);
        }
        for (int q1 = (int)now.size()-1-w4 % 2; q1 > -1; q1--){
            now.push_back(now[q1]);
        }
    }
    ll ans = 0;
    for (int q: now){
        ans += q;
    }
    cout << ans % C << endl;
    return 0;
}
