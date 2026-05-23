// {{{
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
// }}}

using ll = long long;

struct point {
    int x, y;
    point () {}
    point (int x, int y): x(x), y(y) {}

    bool operator < (const point& o) const {
        return x+y < o.x+o.y;
    }
};

int INF = 1LL << 29;

int W, H, N;
point pv[500];

int main() {
    cin >> H >> W >> N;
    for (int j = 0; j < N; ++j) { cin >> pv[j].x >> pv[j].y; }
    sort(pv, pv+N);

    int mm[505][505];
    for (int j = 0; j <= H; ++j) { fill(mm[j], mm[j]+W+1, INF); }
    mm[0][1] = mm[1][0] = 0;

    for (int n = 0; n < N; ++n) {
        int x = pv[n].x, y = pv[n].y;

        int mc = INF;
        vector<int> cv;
        for (int d = 1; d <= H+W+1; ++d) {
            for (int dx = -d; dx <= d; ++dx) {
                int px = x + dx, py = y + d - abs(dx);
                if (0 <= px && px <= H && 0 <= py && py <= W) {
                    mc = min(mc, mm[px][py]);
                }

                py = y - d + abs(dx);
                if (0 <= px && px <= H && 0 <= py && py <= W) {
                    mc = min(mc, mm[px][py]);
                }
            }
            cv.push_back(mc + d - 1);
        }

        for (int i = H+W-1; i >= 0; --i) {
            cv[i] = min(cv[i], cv[i+1]);
        }

        for (int d = 0; d <= H+W; ++d) {
            for (int dx = -d; dx <= d; ++dx) {
                int dy = d - abs(dx);

                int px = x + dx, py = y + dy;
                if (1 <= px && px <= H && 1 <= py && py <= W) {
                    mm[px][py] = min(mm[px][py], cv[d]);
                }

                py = y - dy;
                if (1 <= px && px <= H && 1 <= py && py <= W) {
                    mm[px][py] = min(mm[px][py], cv[d]);
                }
            }
        }
    }

    cout << mm[H][W] << endl;

    return 0;
}

