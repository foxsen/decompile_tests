#include<algorithm>
#include<climits>
#include<cmath>
#include<cstring>
#include<deque>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>

using namespace std;

using lint = long long;
using P = pair<int, int>;
using LLP = pair<long long, long long>;

#define REP(i, x, n) for(int i = (x), i##_len = int(n) ; i < i##_len ; ++i)
#define rep(i, n) for(int i = 0, i##_len = int(n) ; i < i##_len ; ++i)
#define reps(i, n) for(int i = 1, i##_len = int(n) ; i <= i##_len ; ++i)
#define rrep(i, n) for(int i = int(n) - 1 ; i >= 0 ; --i)
#define rreps(i, n) for(int i = int(n) ; i > 0 ; --i)
#define SORT(x) sort((x).begin(), (x).end())
#define SORT_INV(x) sort((x).rbegin(), (x).rend())
#define TWINS(x) cout << ((x) ? "Yay!" : ":(") << endl

const int IINF = (1 << 30) - 1;
const long long LLINF = 1LL << 61;
const int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};
const double EPS = 1e-8;

int dp[101][1 << 15];

template<typename T>
bool chmin(T &_a, T _b){
    if(_a > _b){
        _a = _b;
        return true;
    }else{
        return false;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    while(cin >> n >> m, n){
        vector<int> s(n);
        rep(i, n){
            cin >> s[i];
        }

        vector<int> d(m);
        rep(i, m){
            cin >> d[i];
        }

        SORT(d);

        vector<int> sum(1 << n);
        rep(i, 1 << n){
            int t = 0;
            rep(j, n){
                if(i >> j & 1){
                    t += s[j];
                }
            }
            sum[i] = t;
        }

        fill(dp[0], dp[m + 1], IINF);
        dp[0][0] = 0;

        rep(i, m){
            rep(j, 1 << n){
                chmin(dp[i + 1][j], dp[i][j] + abs(sum[j] - d[i]));
                rep(k, n){
                    chmin(dp[i][j | (1 << k)], dp[i][j]);
                }
            }
        }

        int ans = IINF;
        rep(j, 1 << n){
            chmin(ans, dp[m][j]);
        }

        cout << ans << endl;
    }

    return 0;
}
