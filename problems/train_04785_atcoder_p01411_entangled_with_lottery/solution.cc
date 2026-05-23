// #define _GLIBCXX_DEBUG // for STL debug (optional)
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
using namespace std;

#define debug(...) fprintf(stderr, __VA_ARGS__)
#define int long long int
 
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
typedef pair<int, int> pii;
typedef long long ll;
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const ll INF = 1001001001001001LL;
const ll MOD = 1000000007LL;

double dpn[110][510], dpc[110][510];
int can[510][110][2], exist[510], cnt[510];
signed main() {
    int H, N, P, M, K;
    cin >> H >> N >> P >> M >> K; P--;
    for(int i=0; i<M; i++) {
        int a, b; cin >> a >> b;
        a = H - a;
        exist[a] = true;
        can[a][b-1][1] = can[a][b][0] = true;
    }
    cnt[0] = H - M;
    for(int i=0; i<H; i++) cnt[i+1] = cnt[i] - !exist[i];

    dpc[P][0] = 1.0;
    for(int i=0; i<H; i++) {
        for(int k=0; k<=K; k++) {
            for(int j=0; j<N; j++) {
                // その行にすでに横線があるか
                // K 本全て引き終わった場合
                if(exist[i] or k == K) {
                    if(can[i][j][0]) dpn[j-1][k] += dpc[j][k];
                    else if(can[i][j][1]) dpn[j+1][k] += dpc[j][k];
                    else dpn[j][k] += dpc[j][k];
                }
                else {
                    // 横線を引く場合
                    // まだなにも横線が引かれてない行は cnt[i] 行
                    // 今の行に引かれる確率は (K - k) / cnt[i];
                    double p = 1.0 * (K - k) / cnt[i];
                    double r = 1.0, q = 1.0 / (N - 1);
                    if(j > 0) dpn[j-1][k+1] += dpc[j][k] * p * q, r -= q;
                    if(j+1 < N) dpn[j+1][k+1] += dpc[j][k] * p * q, r -= q;
                    dpn[j][k+1] += dpc[j][k] * p * r;
                    dpn[j][k] += dpc[j][k] * (1 - p);
                }
            }
        }
        fill(dpc[0], dpc[110], 0);
        swap(dpc, dpn);
    }
    double ans = 0.0;
    for(int i=0; i<N; i++) ans = max(ans, dpc[i][K]);
    printf("%.12f\n", ans);
    return 0;
}

