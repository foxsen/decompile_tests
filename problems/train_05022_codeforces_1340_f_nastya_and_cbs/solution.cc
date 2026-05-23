#include <bits/stdc++.h>
using namespace std;
const pair<int, int> MOD = make_pair(1e9 + 7, 1e9 + 9);
const int base = 1e6 + 3;
const int N = 1e5 + 100, B = 600;
pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
  a.first += b.first;
  if (a.first >= MOD.first) a.first -= MOD.first;
  a.second += b.second;
  if (a.second >= MOD.second) a.second -= MOD.second;
  return a;
}
pair<int, int> operator-(pair<int, int> a, pair<int, int> b) {
  a.first -= b.first;
  if (a.first < 0) a.first += MOD.first;
  a.second -= b.second;
  if (a.second < 0) a.second += MOD.second;
  return a;
}
pair<int, int> operator*(pair<int, int> a, int x) {
  return make_pair(1ll * a.first * x % MOD.first,
                   1ll * a.second * x % MOD.second);
}
pair<int, int> operator*(pair<int, int> a, pair<int, int> b) {
  return make_pair(1ll * a.first * b.first % MOD.first,
                   1ll * a.second * b.second % MOD.second);
}
int n, K, q;
int a[N];
pair<int, int> open_Hash[B][B], close_Hash[B];
int szo[B], szc[B];
pair<int, int> base_pow[N], inv_pow[N];
int good[N];
int stk[N];
int bm(int b, int p, int m) {
  if (p == 0) return 1;
  int t = bm(b, p / 2, m);
  t = 1ll * t * t % m;
  if (p & 1) return 1ll * b * t % m;
  return t;
}
void pre() {
  base_pow[0] = {1, 1};
  inv_pow[0] = {1, 1};
  for (int i = 1; i < N; i++) {
    base_pow[i] = base_pow[i - 1] * base;
    inv_pow[i].first = bm(base_pow[i].first, MOD.first - 2, MOD.first);
    inv_pow[i].second = bm(base_pow[i].second, MOD.second - 2, MOD.second);
  }
}
bool recal(int l, int r, int idx) {
  int sz = 0;
  for (int i = l; i <= r; i++) {
    if (a[i] < 0 && sz > 0 && stk[sz - 1] == abs(a[i]))
      sz--;
    else
      stk[sz++] = a[i];
  }
  szo[idx] = szc[idx] = 0;
  bool pos = false;
  for (int i = 0; i < sz; i++) {
    if (stk[i] > 0) pos = true;
    if (stk[i] < 0 && pos) return false;
  }
  close_Hash[idx] = {0, 0};
  for (int i = 0; i < sz; i++) {
    if (stk[i] > 0) break;
    int x = abs(stk[i]);
    int kth = szc[idx];
    close_Hash[idx] = close_Hash[idx] + (base_pow[kth] * x);
    szc[idx]++;
  }
  for (int i = sz - 1; i >= 0; i--) {
    if (stk[i] < 0) break;
    int x = abs(stk[i]);
    int kth = szo[idx];
    open_Hash[idx][szo[idx]++] = (base_pow[kth] * x);
  }
  for (int i = 1; i < szo[idx]; i++) {
    open_Hash[idx][i] = open_Hash[idx][i - 1] + open_Hash[idx][i];
  }
  return true;
}
pair<int, int> all_open[N];
int sz_all;
bool find_hash(int sz, pair<int, int> hhh) {
  assert(sz > 0);
  int psz = 0;
  pair<int, int> h = {0, 0};
  while (psz < sz && sz_all > 0) {
    auto t = all_open[sz_all - 1];
    sz_all--;
    int which_block = t.first, idx = t.second;
    int cur_sz = szo[which_block] - idx;
    assert(cur_sz > 0);
    if (cur_sz + psz < sz) {
      pair<int, int> hh =
          (open_Hash[which_block][szo[which_block] - 1] -
           (idx > 0 ? open_Hash[which_block][idx - 1] : make_pair(0, 0))) *
          inv_pow[idx];
      hh = hh * base_pow[psz];
      h = h + hh;
      psz += cur_sz;
    } else {
      int lage = sz - psz;
      pair<int, int> hh =
          (open_Hash[which_block][idx + lage - 1] -
           (idx > 0 ? open_Hash[which_block][idx - 1] : make_pair(0, 0))) *
          inv_pow[idx];
      hh = hh * base_pow[psz];
      h = h + hh;
      if (idx + lage < szo[which_block])
        all_open[sz_all++] = {which_block, idx + lage};
      psz += lage;
    }
  }
  if (psz < sz) return 0;
  if (hhh != h) return 0;
  return 1;
}
int query(int l, int r) {
  int bl = l / B, br = r / B;
  if (bl == br) {
    int x = recal(l, r, B - 1);
    if (x && szo[B - 1] == 0 && szc[B - 1] == 0) return 1;
    return 0;
  }
  if (recal(l, (bl + 1) * B - 1, B - 2) == 0) return 0;
  if (szc[B - 2] > 0) return 0;
  sz_all = 0;
  if (szo[B - 2] > 0) all_open[sz_all++] = {B - 2, 0};
  for (int b = bl + 1; b < br; b++) {
    if (!good[b]) return 0;
    if (szc[b] == 0) {
      if (szo[b] > 0) all_open[sz_all++] = {b, 0};
      continue;
    }
    int sz = szc[b];
    if (!find_hash(sz, close_Hash[b])) return 0;
    if (szo[b] > 0) all_open[sz_all++] = {b, 0};
  }
  if (recal(br * B, r, B - 1) == 0) return 0;
  if (szo[B - 1] > 0) return 0;
  if (szc[B - 1] > 0 && !find_hash(szc[B - 1], close_Hash[B - 1])) return 0;
  if (sz_all > 0) return 0;
  return 1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  pre();
  cin >> n >> K;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0, j = 0; i < n; i += B, j++) {
    good[j] = recal(i, min(i + B - 1, n - 1), j);
  }
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int idx, x;
      cin >> idx >> x;
      idx--;
      a[idx] = x;
      int b = idx / B;
      int l = b * B, r = min(l + B - 1, n - 1);
      good[b] = recal(l, r, b);
    } else {
      int l, r;
      cin >> l >> r;
      l--, r--;
      if (query(l, r))
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
  }
  return 0;
}
