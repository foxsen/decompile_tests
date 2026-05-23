#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <bitset>
#include <complex>
#include <unistd.h>
#include <cassert>
#include <cctype>
#include <random>
#define _USE_MATH_DEFINES
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> plglg;
typedef pair<double, ll> pdlg;
typedef tuple<int, int, int> tiii;
typedef tuple<ll, ll, ll> tlglglg;
typedef tuple<double, double, double> tddd;
typedef complex<double> xy_t;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
double pi = 3.141592653589793;
ll mod = 1000000007;
int intmax = 2147483647;
int intmin = -2147483648;
ll llmax = 9223372036854775807;
ll llmin = -9223372036854775807;
int iinf = intmax / 8;
ll inf = llmax / 8;
double eps = 1e-11;

ll num[1010][1010];

ll high[2010][2010];
ll middle[2010][2010];
ll low[2010][2010];

ll db[1010];

int main() {
    ll N, D;
    cin >> N >> D;
    for (int i = 0; i < 1010; i++) {
        fill(num[i], num[i] + 1010, 0);
    }
    for (int i = 0; i < 1010; i++) {
        db[i] = i * i;
    }
    for (int i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        x = x % D;
        y = y % D;
        num[x][y]++;
    }
    ll maxnum = 0;
    for (int i = 0; i < D; i++) {
        for (int j = 0; j < D; j++) {
            maxnum = max(maxnum, num[i][j]);
        }
    }
    ll sz = lower_bound(db, db + 1010, maxnum) - db;
    //cout << sz << endl;
    ll hi = sz * D - 1;
    ll lo = (sz - 1) * D - 1;
    for (int i = 0; i < 2010; i++) {
        fill(high[i], high[i] + 2010, 0);
        fill(middle[i], middle[i] + 2010, 0);
        fill(low[i], low[i] + 2010, 0);
    }
    ll highnum = sz * sz;
    ll middlenum = sz * (sz - 1);
    ll lownum = (sz - 1) * (sz - 1);
    for (int i = 0; i < D; i++) {
        for (int j = 0; j < D; j++) {
            if (num[i][j] > highnum) {
                high[i + 1][j + 1]++;
                high[i + D + 1][j + 1]++;
                high[i + 1][j + D + 1]++;
                high[i + D + 1][j + D + 1]++;
            }
            if (num[i][j] > middlenum) {
                middle[i + 1][j + 1]++;
                middle[i + D + 1][j + 1]++;
                middle[i + 1][j + D + 1]++;
                middle[i + D + 1][j + D + 1]++;
            }
            if (num[i][j] > lownum) {
                low[i + 1][j + 1]++;
                low[i + D + 1][j + 1]++;
                low[i + 1][j + D + 1]++;
                low[i + D + 1][j + D + 1]++;
            }
        }
    }
    for (int i = 0; i < 2 * D + 1; i++) {
        for (int j = 1; j < 2 * D + 1; j++) {
            high[i][j] += high[i][j - 1];
            middle[i][j] += middle[i][j - 1];
            low[i][j] += low[i][j - 1];
        }
    }
    for (int i = 1; i < 2 * D + 1; i++) {
        for (int j = 0; j < 2 * D + 1; j++) {
            high[i][j] += high[i - 1][j];
            middle[i][j] += middle[i - 1][j];
            low[i][j] += low[i - 1][j];
        }
    }
    while (hi - lo > 1) {
        ll mid = (hi + lo) / 2;
        //ll a = mid / D;
        ll b = mid % D + 1;
        bool ok = false;
        for (int i = 0; i < D; i++) {
            for (int j = 0; j < D; j++) {
                // bool subok = true;
                // for (int k = 0; k < D; k++) {
                //     for (int l = 0; l < D; l++) {
                //         ll numkl;
                //         if ((i <= k && k <= i + b) || (i <= k + D && k + D <= i + b)) {
                //             if ((j <= l && l <= j + b) || (j <= l + D && l + D <= j + b)) {
                //                 numkl = (a + 1) * (a + 1);
                //             } else {
                //                 numkl = a * (a + 1);
                //             }
                //         } else {
                //             if ((j <= l && l <= j + b) || (j <= l + D && l + D <= j + b)) {
                //                 numkl = a * (a + 1);
                //             } else {
                //                 numkl = a * a;
                //             }
                //         }
                //         if (num[k][l] > numkl) {
                //             subok = false;
                //             break;
                //         }
                //     }
                //     if (!subok) {
                //         break;
                //     }
                // }
                // if (subok) {
                //     ok = true;
                //     break;
                // }
                ll highover = high[i + b][j + b] - high[i][j + b] - high[i + b][j] + high[i][j];
                ll middleover1 = middle[i + D][j + b] - middle[i + b][j + b]
                    - middle[i + D][j] + middle[i + b][j];
                ll middleover2 = middle[i + b][j + D] - middle[i][j + D]
                    - middle[i + b][j + b] + middle[i][j + b];
                ll lowover = low[i + D][j + D] - low[i + b][j + D]
                    - low[i + D][j + b] + low[i + b][j + b];
                //cout << mid << " " << b;
                //cout << " " << highover << " " << middleover1 << " " << middleover2 << " " << lowover << endl;
                if (highover == 0 && middleover1 == 0 && middleover2 == 0 && lowover == 0) {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                break;
            }
        }
        if (ok) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << hi << endl;
}
