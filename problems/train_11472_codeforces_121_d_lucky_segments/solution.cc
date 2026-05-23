#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int M = 1 << 19;
int n, m;
long long k, mn = 1e18, l[N], r[N];
long long lucky[M], dp1[M], dp2[M];
vector<int> vec[M];
inline long long Mul(long long a, long long b) {
  return a && k / a < b ? k + 10 : a * b;
}
inline void Sum(long long &a, long long b) { a = min(a + b, k + 10); }
inline bool check(int L, int R) {
  return lucky[R] - lucky[L] <= mn && dp1[L] + dp2[R] <= k;
}
inline void read_input() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
    mn = min(mn, r[i] - l[i]);
  }
}
inline void solve() {
  int sz = 0;
  long long sum = 0;
  for (int i = 1; i < 19; i++)
    for (int j = 0; j < 1 << i; j++, m++)
      for (int p = i - 1; ~p; p--) (lucky[m] *= 10) += j >> p & 1 ? 7 : 4;
  for (int i = 0; i < n; i++)
    vec[lower_bound(lucky, lucky + m, l[i]) - lucky].push_back(i);
  for (int i = m - 1; ~i; i--) {
    Sum(sum, Mul(sz, lucky[i + 1] - lucky[i]));
    for (auto p : vec[i + 1]) {
      Sum(sum, l[p] - lucky[i]);
      sz++;
    }
    dp1[i] = sum;
  }
  for (int i = sz = sum = 0; i < m; i++) vec[i].clear();
  for (int i = 0; i < n; i++)
    vec[lower_bound(lucky, lucky + m, r[i]) - lucky].push_back(i);
  for (int i = 0; i < m; i++) {
    Sum(sum, Mul(sz, (lucky[i] - lucky[i - 1])));
    for (auto p : vec[i]) {
      Sum(sum, lucky[i] - r[p]);
      sz++;
    }
    dp2[i] = sum;
  }
}
inline void write_output() {
  int ans = 0;
  for (int i = 0; i < m; i++) {
    int L = i - 1, R = m;
    while (L + 1 < R) {
      int mid = L + R >> 1;
      (check(i, mid) ? L : R) = mid;
    }
    ans = max(ans, L - i + 1);
  }
  cout << ans;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  read_input(), solve(), write_output();
  return 0;
}
