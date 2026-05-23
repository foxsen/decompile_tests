#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const long long longinf = 1LL << 60;
const long long mod = 1e9 + 7;
const long double eps = 1e-10;
template <typename T1, typename T2>
inline void chmin(T1 &a, T2 b) {
  if (a > b) a = b;
}
template <typename T1, typename T2>
inline void chmax(T1 &a, T2 b) {
  if (a < b) a = b;
}
void solve() {
  int n;
  cin >> n;
  vector<long long> A(n);
  for (int i = (int)(0); i < (int)(n); i++) cin >> A[i];
  long long ans = 0;
  int l = 0, r = n - 1;
  while (l < r) {
    long long tmp = 0;
    while (l < n && A[l] + tmp >= 0) {
      tmp += A[l];
      l++;
    }
    if (l == n) break;
    A[l] += tmp;
    tmp = 0;
    while (r >= 0 && A[r] + tmp <= 0) {
      tmp += A[r];
      r--;
    }
    if (r == -1) break;
    A[r] += tmp;
    if (l >= r) break;
    long long mn = min(-A[l], A[r]);
    ans += mn;
    A[l] += mn;
    A[r] -= mn;
  }
  cout << ans << endl;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
