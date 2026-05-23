#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <deque>
#include <string>

#include <algorithm>
#include <numeric>

#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>

#define pb push_back
#define pbk pop_back
#define mp make_pair
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define foreach(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define len(a) ((int) (a).size())

#ifdef CUTEBMAING
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

using namespace std;

typedef long long int64;
typedef long double ld;
typedef unsigned long long lint;

const int inf = (1 << 30) - 1;
const int64 linf = (1ll << 62) - 1;
const int N = 1e6 + 100;

int n, m, q;
int a[N];

bool used[N];
vector<int> perm;

int it[N];
set<int> qt[N];
int pos[N];

int main() {
#ifdef XCODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> m >> q;
    for (int i = 0; i < q; i++) {
        scanf("%d", &a[i]), a[i]--;
    }
    for (int i = q - 1; i >= 0; i--) {
        if (!used[a[i]]) {
            perm.pb(a[i]);
            used[a[i]] = true;
        }
    }
    for (int i = 0; i < len(perm); i++) {
        pos[perm[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        qt[it[i]].insert(i);
    }
    for (int i = q - 1; i >= 0; i--) {
        int cur = pos[a[i]];
        if (len(qt[cur]) == 0) {
            continue;
        }
        int start = *qt[cur].begin();
        qt[cur].erase(qt[cur].begin());
        qt[cur + 1].insert(start);
    }
    static int last[N];
    for (int i = 0; i < N; i++) {
        for (int j : qt[i]) {
            last[j] = i;
        }
    }
    int minLast = *min_element(last, last + n);
    static bool cused[N];
    for (int j = 0; j < minLast; j++) {
        cused[perm[j]] = true;
    }
    int it = 0;
    for (int j = minLast; j < len(perm); j++) {
        while (cused[it]) {
            it++;
        }
        if (it != perm[j]) {
            puts("No");
            return 0;
        }
        it++;
    }
    puts("Yes");
    return 0;
}
