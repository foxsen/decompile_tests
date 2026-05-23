#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>
#include <bitset>
#include <stack>

using namespace std;
using ll = long long;
using ull = unsigned long long;

using P = pair<int, int>;
using R = array<ll, 2>;
using T = array<R, 3>;


const int MN = 40040;
const ll INF = 1LL<<55;

int n;
array<ll, 3> po[MN][6];
T ar[MN];
T now;

vector<int> nidx[MN];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        //x, y, (x+y)
        ar[i] = {{{INF, -INF}, {INF, -INF}, {INF, -INF}}};
        for (int j = 0; j < 6; j++) {
            ll a, b;
            scanf("%lld %lld", &a, &b);
            po[i][j] = {b, a, a+b};
            ll data[3] = {b, a, a+b};
            for (int y = 0; y < 3; y++) {
                ar[i][y][0] = min(ar[i][y][0], data[y]);
                ar[i][y][1] = max(ar[i][y][1], data[y]);
            }
        }
    }

    static P idx[MN*6];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            idx[i*6+j] = P(i, j);
        }
    }

    for (int i = 0; i < 3; i++) {
        sort(idx, idx+n*6, [&](const P &l, const P &r){
            auto pl = po[l.first][l.second];
            auto pr = po[r.first][r.second];
            if (pl[i] != pr[i]) {
                return pl[i] < pr[i];
            }
            return pl[(i+1)%3] < pr[(i+1)%3];
        });

        for (int i = 0; i < 6*n-1; i++) {
            nidx[idx[i].first].push_back(idx[i+1].first);
            nidx[idx[i+1].first].push_back(idx[i].first);
        }
    }
    now = {{{0, 0}, {0, 0}, {0, 0}}};
    static bool used[MN] = {};
    int uc = 0;
    while (true) {
        bool cng = false;
        queue<int> s;
        for (int i = 0; i < n; i++) {
            if (used[i]) continue;
            s.push(i);
        }
        while (!s.empty()) {
            int i = s.front(); s.pop();
            if (used[i]) continue;
            bool f1 = true, f2 = false;
            auto a = ar[i];
            for (int j = 0; j < 3; j++) {
                if (a[j][1] < now[j][0] or now[j][1] < a[j][0]) {
                    f1 = false;
                    break;
                }
                if (!(a[j][0] < now[j][0] and now[j][1] < a[j][1])) {
                    f2 = true;
                }
            }
            if (f1 && f2) {
                cng = used[i] = true;
                uc++;
                for (int j = 0; j < 3; j++) {
                    now[j][0] = min(now[j][0], a[j][0]-1);
                    now[j][1] = max(now[j][1], a[j][1]+1);
                }
                for (int j: nidx[i]) {
                    s.push(j);
                }
            }
        }
        if (!cng) break;
//        printf("%d\n", uc);
    }
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        ll y, x;
        scanf("%lld %lld", &y, &x);
        ll p[3] = {x, y, x+y};
        bool f = true;
        for (int k = 0; k < 3; k++) {
            if (p[k] < now[k][0] or now[k][1] < p[k]) {
                f = false;
                break;
            }
        }
        if (f) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}