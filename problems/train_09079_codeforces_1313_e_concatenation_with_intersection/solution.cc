#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e6 + 11;
const long long oo = 1e17 + 11;
const long long MOD = 1e9 + 7;
const long long base = 41;
int tcases = 1;
int N, M;
int L[maxN], R[maxN];
long long powHash[maxN], res = 0;
long long hhh[maxN];
class I_love_char_array {
 public:
  int len;
  char str[maxN];
  long long hash[maxN];
  long long gethash(int l, int r) {
    return ((hash[r] - hash[l - 1] * powHash[r - l + 1]) % MOD + MOD) % MOD;
  }
  void run() {
    scanf("%s", str + 1);
    len = strlen(str + 1);
    for (int i = 1; i <= len; ++i)
      hash[i] = (hash[i - 1] * base + str[i] - 'a' + 1) % MOD;
  }
} a, b, s;
void buildPreSubffiixx() {
  for (int i = 1; i <= N; ++i) {
    int r = min(M, N - i + 1), l = 0, v = 0;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (a.gethash(i, i + mid - 1) == s.gethash(1, mid)) {
        v = mid;
        l = mid + 1;
      } else
        r = mid - 1;
    }
    L[i] = v;
    l = 0, r = min(i, M), v = 0;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (b.gethash(i - mid + 1, i) == s.gethash(M - mid + 1, M)) {
        v = mid;
        l = mid + 1;
      } else
        r = mid - 1;
    }
    R[i] = v;
  }
}
class I_love_segment_tree {
 public:
  long long F[maxN * 4];
  int G[maxN * 4];
  void update(int k, int l, int r, int v, int x) {
    if (l > v || r < v) return;
    if (l == r) {
      F[k] += x * v;
      G[k] += x;
      return;
    }
    int mid = (l + r) >> 1;
    update(k << 1, l, mid, v, x);
    update(k << 1 | 1, mid + 1, r, v, x);
    F[k] = F[k << 1] + F[k << 1 | 1];
    G[k] = G[k << 1] + G[k << 1 | 1];
  }
  pair<long long, int> sum(int k, int l, int r, int L, int R) {
    if (l > R || L > r) return make_pair(0, 0);
    if (L <= l && r <= R) return make_pair(F[k], G[k]);
    int mid = (l + r) >> 1;
    pair<long long, int> x = sum(k << 1, l, mid, L, R),
                         y = sum(k << 1 | 1, mid + 1, r, L, R);
    return make_pair(x.first + y.first, x.second + y.second);
  }
  void init() {}
} IT;
void testcase() {
  scanf("%d%d", &N, &M);
  powHash[0] = 1;
  for (int i = 1; i <= max(N, M); ++i)
    powHash[i] = (powHash[i - 1] * base) % MOD;
  a.run();
  b.run();
  s.run();
  buildPreSubffiixx();
  int j = 0;
  for (int i = 1; i <= N; ++i) {
    while (j < N && j < i + M - 2) {
      IT.update(1, 1, M, R[++j], 1);
    }
    if (L[i] >= M) {
      pair<long long, int> tmp = IT.sum(1, 1, M, 1, M - 1);
      res += tmp.first;
      tmp = IT.sum(1, 1, M, M, M);
      res += 1LL * tmp.second * (M - 1);
    } else {
      pair<long long, int> tmp = IT.sum(1, 1, M, M - L[i], M - 1);
      res += 1LL * tmp.second * (L[i] - M + 1) + tmp.first;
      tmp = IT.sum(1, 1, M, M, M);
      res += 1LL * tmp.second * L[i];
    }
    IT.update(1, 1, M, R[i], -1);
  }
  printf("%lli", res);
}
int main() {
  for (int i = 1; i <= tcases; ++i) testcase();
  return 0;
}
