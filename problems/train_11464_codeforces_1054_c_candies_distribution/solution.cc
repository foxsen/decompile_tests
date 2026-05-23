#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool umax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
template <class T>
T min(T a, T b, T c) {
  return min(a, min(b, c));
}
template <class T>
T max(T a, T b, T c) {
  return max(a, max(b, c));
}
const long long linf = 2e17;
const int inf = 2e9;
void Fan_chipu();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  cout << fixed;
  Fan_chipu();
}
const int maxn = 1e3 + 7;
int n;
int le[maxn], ri[maxn];
int ans[maxn];
void Fan_chipu() {
  cin >> n;
  ans[0] = n;
  for (int i = 1; i <= (int)(n); ++i) cin >> le[i], ans[i] = n;
  for (int i = 1; i <= (int)(n); ++i) cin >> ri[i];
  for (int i = 1; i <= (int)(n); ++i) {
    ans[i] = n - ri[i] - le[i];
  }
  bool OK = true;
  for (int i = 1; i <= (int)(n); ++i) {
    for (int j = 1; j <= n; ++j) {
      if (j < i and ans[j] > ans[i]) --le[i];
      if (j > i and ans[j] > ans[i]) --ri[i];
    }
    if (le[i] != 0 or ri[i] != 0 or ans[i] < 1) {
      cout << "NO";
      return;
    }
  }
  cout << "YES\n";
  for (int i = 1; i <= (int)(n); ++i) cout << ans[i] << ' ';
}
