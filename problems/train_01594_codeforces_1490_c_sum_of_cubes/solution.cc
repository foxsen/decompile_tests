#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1e4 + 4;
map<ll, bool> frq;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int test; cin >> test;

    for (int i = 1; i < N; i++)
        frq [1ll * i * i * i] = true;

    while (test--) {
        ll n; cin >> n;
        bool mark = false;
        for (ll i = 1; i * i * i < n; i++) {
            ll dif = n - i * i * i;
            if (frq[dif] == true) {
                mark = true;
                break;
            }
        }
        if (mark) cout << "YES\n";
        else cout << "NO\n";
    }
}