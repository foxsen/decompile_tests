#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const int MAXN = 1e6 + 10;
pair<int, int> st1[21][MAXN];
int query_min(int l, int r) {
  int k = 32 - __builtin_clz(r - l + 1) - 1;
  return min(st1[k][l], st1[k][r - (1 << k) + 1]).second;
}
int query_max(int l, int r) {
  int k = 32 - __builtin_clz(r - l + 1) - 1;
  return max(st1[k][l], st1[k][r - (1 << k) + 1]).second;
}
void solve(int tc) {
  int n;
  cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    st1[0][i] = {a[i], i};
  }
  for (int i = 1; i < 21; i++) {
    for (int j = 1; j <= n; j++) {
      if (j + (1 << i) - 1 <= n) {
        st1[i][j] = min(st1[i - 1][j], st1[i - 1][j + (1 << (i - 1))]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    int lb = 1, rb = i;
    while (lb < rb) {
      int mid = (lb + rb) / 2;
      if (query_min(mid, i) == i) {
        rb = mid;
      } else {
        lb = mid + 1;
      }
    }
    int lb2 = i, rb2 = n;
    while (lb2 < rb2) {
      int mid = (lb2 + rb2 + 1) / 2;
      if (query_min(i, mid) == i) {
        lb2 = mid;
      } else {
        rb2 = mid - 1;
      }
    }
    ans -= (long long)a[i] * (long long)(i - lb + 1) * (long long)(lb2 - i + 1);
  }
  for (int i = 1; i <= n; i++) {
    st1[0][i] = {a[i], i};
  }
  for (int i = 1; i < 21; i++) {
    for (int j = 1; j <= n; j++) {
      if (j + (1 << i) - 1 <= n) {
        st1[i][j] = max(st1[i - 1][j], st1[i - 1][j + (1 << (i - 1))]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    int lb = 1, rb = i;
    while (lb < rb) {
      int mid = (lb + rb) / 2;
      if (query_max(mid, i) == i) {
        rb = mid;
      } else {
        lb = mid + 1;
      }
    }
    int lb2 = i, rb2 = n;
    while (lb2 < rb2) {
      int mid = (lb2 + rb2 + 1) / 2;
      if (query_max(i, mid) == i) {
        lb2 = mid;
      } else {
        rb2 = mid - 1;
      }
    }
    ans += (long long)a[i] * (long long)(i - lb + 1) * (long long)(lb2 - i + 1);
  }
  cout << ans << "\n";
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  int cnt = 0;
  while (t--) solve(++cnt);
}
