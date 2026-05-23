#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> P;

#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for (ll i=(a);i<(b);i++)
#define RFOR(i,a,b) for (ll i=(b)-1;i>=(a);i--)
#define REP(i,n) for (ll i=0;i<(n);i++)
#define RREP(i,n) for (ll i=(n)-1;i>=0;i--)
#define debug(x) cout<<#x<<": "<<x<<endl
#define pb push_back
#define ALL(a) (a).begin(),(a).end()

const ll linf = 1e18;
const int inf = 1e9;
const double eps = 1e-12;
const double pi = acos(-1);

template<typename T>
istream& operator>>(istream& is, vector<T>& vec) {
    EACH(x,vec) is >> x;
    return is;
}
template<typename T>
ostream& operator<<(ostream& os, vector<T>& vec) {
    REP(i,vec.size()) {
        if (i) os << " ";
        os << vec[i];
    }
    return os;
}
template<typename T>
ostream& operator<<(ostream& os, vector< vector<T> >& vec) {
    REP(i,vec.size()) {
        if (i) os << endl;
        os << vec[i];
    }
    return os;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    ll n, m;
    while ( cin >> n >> m, n || m ) {
        vector<ll> v(n); cin >> v;
        REP(i, n) v[i] %= m;
        REP(i, n-1) v[i+1] = (v[i]+v[i+1])%m;
        set<ll> s; s.insert(0);
        ll ans = 0;
        REP(i, n) {
            ans = max(ans, v[i]);
            if ( s.upper_bound(v[i]) != s.end() ) {
                ans = max(ans, (v[i]-*s.upper_bound(v[i])+m)%m);
            }
            s.insert(v[i]);
        }
        cout << ans << endl;
    }
}