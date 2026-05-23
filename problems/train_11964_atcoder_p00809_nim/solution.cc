#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pl;
#define vi vector<int>
#define vl vector<long long>
#define vvi vector< vector<int> >
#define vvl vector< vector<ll> >
#define vp vector<P>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPD(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define FORD(i, a, b) for (int i = (int)(a); i >= (int)(b); i--)
#define INF 1e18
#define INFTY 1e9
const int mod = 1000000007;
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))

template<class T> bool chmax(T &a, const T & b) {
    if (a<b) {
        a = b;
        return true;
    }
    return false;
}

template<class T> bool chmin(T &a, const T & b) {
    if (a>b) {
        a = b;
        return true;
    }
    return false;
}

//cout << fixed << setprecision(10) << y << endl;
struct edge {int to, cost;};
vector< vector<edge> > es;

int gcd(int a, int b) {
    int r = a % b;
    if (r == 0) return b;
    return gcd(b, r);
}

ll lcm(ll a, ll b) {
    return a/gcd(a, b)*b;
}


int main() {
    while (true) {
        int n, s;
        cin >> n;
        if (n == 0) break;
        cin >> s;
        int p[2*n];
        REP(i, 2*n) {
            cin >> p[i];
        }
        int dp[2*n][s+1];
        REP(i, 2*n) {
            REP(j, s+1) {
                dp[i][j] = -1;
            }
        }
        FOR(j, 1, s+1) {
            REP(i, 2*n) {
                if (j == 1) dp[i][j] = 0;
                else {
                    FOR(k, 1, p[i]+1) {
                        if (j - k < 1) break;
                        else if (dp[(i+1)%(2*n)][j-k] == 0) dp[i][j] = 1;
                    }
                    if (dp[i][j] == -1) dp[i][j] = 0;
                }
            }
        }
        cout << dp[0][s] << endl;
    }
    return 0;
}
