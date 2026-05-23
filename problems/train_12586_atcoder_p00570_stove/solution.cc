#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = int(1e5 + 5);
#define REP(i, n) for (int i = 0; i < n; i++)

int main() {
    ll n, k, t[MAX_N], d[MAX_N], ans = 0;
    cin >> n >> k;
    REP(i,n){
        cin >> t[i];
    }
    REP(i,n-1){
        d[i] = t[i+1] - t[i];
    }
    sort(d,d+n-1);
    REP(i,n-k){
        ans += d[i];
    }
    cout << ans+k << endl;
    return 0;
}

