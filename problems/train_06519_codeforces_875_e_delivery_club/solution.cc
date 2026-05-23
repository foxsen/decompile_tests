#include <bits/stdc++.h>
using namespace std;
void re() { vector<int> b(1e10); }
const int N = 1e5 + 3;
const int LOG = 17;
int n;
int s1, s2;
int a[N];
int st_left_min[LOG][N], st_right_min[LOG][N], st_left_max[LOG][N],
    st_right_max[LOG][N], par_left[LOG][N], par_right[LOG][N];
void build_sparse_table() {
  for (int i = 0; i < LOG; ++i) {
    st_left_min[i][0] = st_left_max[i][0] = a[0];
    par_left[i][0] = 0;
    st_right_min[i][n - 1] = st_left_min[i][0] = a[n - 1];
    par_right[i][n - 1] = n - 1;
  }
  for (int i = 1; i < n; ++i) {
    st_left_min[0][i] = st_left_max[0][i] = a[i];
    par_left[0][i] = i - 1;
    for (int j = 1; j < LOG; ++j) {
      par_left[j][i] = par_left[j - 1][par_left[j - 1][i]];
      st_left_min[j][i] =
          min(st_left_min[j - 1][i], st_left_min[j - 1][par_left[j - 1][i]]);
      st_left_max[j][i] =
          max(st_left_max[j - 1][i], st_left_max[j - 1][par_left[j - 1][i]]);
    }
  }
  for (int i = n - 2; i >= 0; --i) {
    st_right_min[0][i] = st_right_max[0][i] = a[i];
    par_right[0][i] = i + 1;
    for (int j = 1; j < LOG; ++j) {
      par_right[j][i] = par_right[j - 1][par_right[j - 1][i]];
      st_right_min[j][i] =
          min(st_right_min[j - 1][i], st_right_min[j - 1][par_right[j - 1][i]]);
      st_right_max[j][i] =
          max(st_right_max[j - 1][i], st_right_max[j - 1][par_right[j - 1][i]]);
    }
  }
}
char did_log[N];
int log_val[N];
int my_log(int n) {
  if (n == 1) return 0;
  if (did_log[n]) return log_val[n];
  did_log[n] = 1;
  int pw = my_log(n - 1);
  log_val[n] = pw;
  if ((1LL << (pw + 1LL)) <= n) ++log_val[n];
  return log_val[n];
}
int get_max(int l, int r) {
  int pw = my_log(r - l + 1);
  return max(st_right_max[pw][l], st_left_max[pw][r]);
}
int get_min(int l, int r) {
  int pw = my_log(r - l + 1);
  return min(st_right_min[pw][l], st_left_min[pw][r]);
}
int t[2][4 * N];
void build(int v, int tl, int tr) {
  if (tl == tr) {
    t[0][v] = t[1][v] = 0;
    return;
  }
  t[0][v] = t[1][v] = -1;
  int tm = tl + tr >> 1;
  build(v << 1, tl, tm);
  build((v << 1) + 1, tm + 1, tr);
}
void push(int v, int turn) {
  if (t[turn][v] != -1) {
    t[turn][v << 1] = t[turn][(v << 1) + 1] = t[turn][v];
    t[turn][v] = -1;
  }
}
void update(int v, int tl, int tr, int l, int r, int turn) {
  if (l > r) return;
  if (tl == l && tr == r) {
    t[turn][v] = 1;
    return;
  }
  push(v, turn);
  int tm = tl + tr >> 1;
  update(v << 1, tl, tm, l, min(r, tm), turn);
  update((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r, turn);
}
int get(int v, int tl, int tr, int pos, int turn) {
  if (tl == tr) return t[turn][v];
  push(v, turn);
  int tm = tl + tr >> 1;
  if (pos <= tm)
    return get(v << 1, tl, tm, pos, turn);
  else
    return get((v << 1) + 1, tm + 1, tr, pos, turn);
}
int bin_search(int l, int r, int zero, int val) {
  int start = l;
  while (l < r) {
    int m = l + r >> 1;
    if (get_max(start, m) - zero <= val && zero - get_min(start, m) <= val)
      l = m + 1;
    else
      r = m;
  }
  return l - 1;
}
bool solve(int max_dist) {
  if (abs(s1 - s2) > max_dist) return false;
  build(1, 0, n - 1);
  update(1, 0, n - 1, 0, bin_search(0, n, s1, max_dist), 1);
  update(1, 0, n - 1, 0, bin_search(0, n, s2, max_dist), 0);
  for (int i = 0; i < n; ++i) {
    for (int turn : {0, 1}) {
      if (!get(1, 0, n - 1, i, turn)) continue;
      update(1, 0, n - 1, i + 1, bin_search(i + 1, n, a[i], max_dist), !turn);
    }
  }
  return get(1, 0, n - 1, n - 1, 0) || get(1, 0, n - 1, n - 1, 1);
}
int main() {
  scanf("%d%d%d", &n, &s1, &s2);
  for (int i = 0; i < n; ++i) scanf("%d", a + i);
  build_sparse_table();
  int l = 0, r = 1e9 + 1;
  while (l < r) {
    int m = l + r >> 1;
    if (solve(m))
      r = m;
    else
      l = m + 1;
    if (l == r - 1)
      if (solve(l))
        r = l;
      else
        l = r;
  }
  printf("%d", r);
}
