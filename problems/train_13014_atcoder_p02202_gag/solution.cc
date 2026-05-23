#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(int i = a; i < b; i++)

int main(){
    ll N; cin >> N;
    ll ans = 0;
    vector<ll> V(N);
    rep(i, 0, N) cin >> V[i];
    rep(i, 0, N) ans += V[i] - (i + 1);

    cout << ans << endl;
}
