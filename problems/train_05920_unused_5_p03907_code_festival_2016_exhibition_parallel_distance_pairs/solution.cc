#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <functional>
#include <numeric>
#include <limits>
using namespace std;

#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)

int N;
int A[100010], B[100010];

int solve() {
  try {
    rep (i, N) {
      if ((A[i] == 0) != (i == 0)) throw 0;
      if ((B[i] == 0) != (i == 1)) throw 0;
    }

    int D = B[0];
    if (A[1] != D) throw 0;

    map<pair<int, int>, int> cnt;
    rep (i, N) cnt[mp(A[i], B[i])] += 1;

    map<int, map<int, int>> taba;
    rep (i, N) {
      taba[A[i] + B[i]][A[i]] += 1;
    }

    for (int d = 0; d < D; ++d) {
      if (taba.count(d)) throw 0;
    }

    int ans = N - 1;

    for (auto &i : taba) {
      int d = i.first;
      map<int, int> &m = i.second;

      int request = 0;  // request from left
      for (const auto &j : m) {
        int a = j.first, b = d - a, c = j.second;
        if (a > 0 && cnt[mp(a - 1, b - 1)] + cnt[mp(a - 1, b)] + cnt[mp(a - 1, b + 1)] == 0) {
          throw 0;
        }

        int hige;
        if (cnt[mp(a - 1, b - 1)]) hige = max(0, c - request);
        else hige = 0;
        c -= hige;

        ans += max(0, request - c);

        if (cnt[(mp(a + 1, b - 1))] > 0) {
          request = c;
        } else if (b > 0) {
          if (cnt[mp(a - 1, b - 1)] + cnt[mp(a, b - 1)] + cnt[mp(a + 1, b - 1)] == 0) {
            throw 0;
          }
          ans += c;
          request = 0;
        }
      }
    }
    return ans;
  } catch (...) {
    return -1;
  }
}

int main() {
  scanf("%d", &N);
  rep (i, N) {
    scanf("%d%d", &A[i], &B[i]);
  }

  int ans1 = solve();

  rep (i, N) swap(A[i], B[i]);
  swap(A[0], A[1]);
  swap(B[0], B[1]);
  int ans2 = solve();

  assert(ans1 == ans2);
  printf("%d\n", ans1);

  return 0;
}
