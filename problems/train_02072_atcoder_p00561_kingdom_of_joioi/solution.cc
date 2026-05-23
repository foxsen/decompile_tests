#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
    for (T& x : v) is >> x;
    return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    if (!v.empty()) {
        os << v.front();
        for (int i = 1; i < v.size(); ++i) os << ' ' << v[i];
    }
    return os;
}

int main() {
#ifdef LBT
    freopen("test.in", "r", stdin);
    int nol_cl = clock();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    cin >> A;
    vector<pair<int, pair<int, int>>> pos;
    pos.reserve(N * M);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) pos.emplace_back(A[i][j], make_pair(i, j));
    sort(pos.begin(), pos.end());
    int ans = numeric_limits<int>::max();
    for (int rep = 1; rep <= 4; ++rep) {
        int mx = numeric_limits<int>::min(), mn = numeric_limits<int>::max();
        vector<int> R(N);
        for (int i = 0; i < N * M - 1; ++i) {
            int x, y;
            tie(x, y) = pos[i].second;
            while (x >= 0 && R[x] <= y) {
                while (R[x] <= y) {
                    mx = max(mx, A[x][R[x]]);
                    mn = min(mn, A[x][R[x]]);
                    ++R[x];
                }
                --x;
            }
            ans = min(ans, max(pos.back().first - pos[i + 1].first, mx - mn));
        }
        if (rep & 1) {
            reverse(A.begin(), A.end());
            for (auto& pr : pos) pr.second.first = N - 1 - pr.second.first;
        } else if (rep & 2) {
            for (int i = 0; i < N; ++i) reverse(A[i].begin(), A[i].end());
            for (auto& pr : pos) pr.second.second = M - 1 - pr.second.second;
        }
    }
    cout << ans << '\n';

#ifdef LBT
    LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
    return 0;
}
