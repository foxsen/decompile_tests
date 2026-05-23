//Be Name Khoda

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back
#define pp pop_back
#define all(x) x.begin(), x.end()
#define pll pair< ll, ll >

const ll mxn = 1e5 + 10; 
ll t, n, k, q;
vector<ll> v, v2;

void input() {

    v.clear(), v2.clear(); 

    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> q;
        v.pb(q);
    }

}

void solve() {

    ll mn = v[0] + 1, mx = v[0] + k;
    bool ch = 1;

    for(int i = 1; i < n - 1; i++) {

        if(mn > v[i] + k - 1 + k) {
            ch = 0;
            break;
        }
        if(mx <= v[i]) {
            ch = 0;
            break;
        }

        int x = mn, y = mx;

        x = max(mn - (k - 1), v[i] + 1);
        y = min(mx + k - 1, v[i] + k - 1 + k);

        mn = x, mx = y;

    }
    int x = v[n - 1] + 1, y = v[n - 1] + k;
    if(mn > y || mx < x) {
        ch = 0;
    }
    if(!ch) {
        cout << "NO\n";
    }
    else {
        cout << "Yes\n";
    }

}

int main() {

    ios::sync_with_stdio(false);

    cin >> t;
    while(t--) {
        input(), solve();
    }
    
    return 0;
    
}
/*

*/