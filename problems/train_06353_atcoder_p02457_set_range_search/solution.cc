//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    set<int> se;
    while(q--) {
        int t, x;
        cin >> t >> x;
        if(t == 0) {
            se.insert(x);
            cout << se.size() << '\n';
        } else if(t == 1) {
            auto itr = se.find(x);
            cout << (itr != se.end()) << '\n';
        } else if(t == 2) {
            se.erase(x);
        } else {
            int r;
            cin >> r;
            auto itr = se.lower_bound(x);
            for(;*itr <= r and itr != se.end(); itr = next(itr)) {
                cout << *itr << '\n';
            }
        }
    }
}
