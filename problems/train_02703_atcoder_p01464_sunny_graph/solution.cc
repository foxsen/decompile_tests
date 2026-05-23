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

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr int TEN(int n) {return (n==0)?1:10*TEN(n-1);}

const int N = 210;

struct MT {
    bool g[N][N];
    int mt[N];
};

vector<int> res;
bool used[N][2];
bool dfs(const MT &mt, int p, int b) {
    used[p][b] = true;
    if (mt.mt[p] == -1 and b == 1) {
        res.push_back(p);
        return true;
    }
    if (b == 0) {
        for (int q = 0; q < N; q++) {
            if (mt.g[p][q] == false) continue;
            if (used[q][1-b]) continue;
            if (dfs(mt, q, 1-b)) {
                res.push_back(p);
                return true;
            }
        }   
    } else {
        int q = mt.mt[p];
        if (!used[q][1-b] and dfs(mt, q, 1-b)) {
            res.push_back(p);
            return true;
        }
    }
    return false;
}

vector<int> findMwalk(const MT &mt) {
    /*
     M?¢????????????£?????????????????????
     ??????????????£?????????vector
     */
    res.clear();
    memset(used, 0, sizeof(used));
    for (int i = 0; i < N; i++) {
        if (mt.mt[i] != -1 or used[i][0]) continue;
        if (dfs(mt, i, 0)) return res;
    }
    return vector<int>();
}

bool maxmt(MT &mt) {
    auto v = findMwalk(mt);
    if (v.size() == 0) return false;

    int m = (int)v.size();
    int ok[N]; //???????????§??????
    fill_n(ok, N, -1);
    for (int i = 0; i < m; i++) {
        int d = v[i];
        if (ok[d] != -1) {
            int l = ok[d], r = i;
            MT nmt = mt;
            for (int idx = l+1; idx < r; idx++) {
                int j = v[idx];
                //nmt clear
                for (int k = 0; k < N; k++) {
                    if (nmt.g[j][k] and d != k) {
                        nmt.g[d][k] = true;
                        nmt.g[k][d] = true;
                    }
                    nmt.g[j][k] = nmt.g[k][j] = false;
                }
                nmt.mt[j] = -1;
            }
            bool f = maxmt(nmt);

            if (!f) return false;
            copy_n(nmt.mt, N, mt.mt);
            int e = mt.mt[d];
            if (e == -1) return true;
            mt.mt[d] = mt.mt[e] = -1;
            for (int idx = l; idx < r; idx++) {
                int j = v[idx];
                if (!mt.g[e][j]) continue;
                mt.mt[e] = j;
                mt.mt[j] = e;
                rotate(v.begin()+l, v.begin()+idx, v.begin()+r);
                assert((r - (l+1)) % 2 == 0);
                for (int k = l+1; k < r; k += 2) {
                    mt.mt[v[k]] = v[k+1];
                    mt.mt[v[k+1]] = v[k];
                }
                return true;
            }
            assert(false);
        }
        ok[d] = i;
    }
    for (int i = 0; i < m; i += 2) {
        mt.mt[v[i]] = v[i+1];
        mt.mt[v[i+1]] = v[i];
    }
    return true;
}

MT first;
int solve() {
    int co = 0;
    while (maxmt(first)) {
        co++;
    }
    return co;
}


int main() {
    memset(first.g, 0, sizeof(first.g));
    memset(first.mt, -1, sizeof(first.mt));
    int n, m;
    scanf("%d %d", &n, &m); n--;
    bool one[N] = {};
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a > b) swap(a, b);
        if (a == 1) {
            one[b-2] = true;
        } else {
            a -= 2; b -= 2;
            first.g[a][b] = first.g[b][a] = true;
        }
    }
    solve();
    for (int i = 0; i < n; i++) {
        if (first.mt[i] == -1) {
            printf("No\n");
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!one[i]) continue;
        first.g[i][n] = first.g[n][i] = true;
    }
    auto v = findMwalk(first);
    if (v.size() == 0) {
        printf("No\n");
    } else {
        printf("Yes\n");
    }
    return 0;
}