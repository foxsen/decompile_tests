#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { cin >> x; }
void _R(int64_t &x) { cin >> x; }
void _R(double &x) { cin >> x; }
void _R(long double &x) { cin >> x; }
void _R(char &x) { cin >> x; }
void _R(char *x) { cin >> x; }
void _R(string &x) { cin >> x; }
void R() {}
template <class T, class... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
template <class T>
void _W(const T &x) {
  cout << x;
}
void _W(const int &x) { cout << x; }
void _W(const int64_t &x) { cout << x; }
void _W(const double &x) { cout << fixed << setprecision(8) << x; }
void _W(const long double &x) { cout << fixed << setprecision(16) << x; }
void _W(const char &x) { cout << x; }
void _W(const char *x) { cout << x; }
void _W(const string &x) { cout << x; }
template <class T, class U>
void _W(const pair<T, U> &x) {
  _W(x.first);
  cout << ' ';
  _W(x.second);
}
template <class T>
void _W(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _W(*i++))
    if (i != x.cbegin()) cout << ' ';
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &...tail) {
  _W(head);
  cout << (sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
const int N = 1e6 + 3;
char room[N];
int dp[N];
int n, k;
int get(int l, int r) { return dp[min(r, n)] - dp[max(1, l) - 1]; }
int get_ans(int x) {
  int r = n + 1;
  int l = 0;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (get(x, x + mid) + get(x - mid, x) - 2 >= k) {
      r = mid;
    } else {
      l = mid;
    }
  }
  return r;
}
void solve() {
  R(n, k);
  for (int i = (1); i < (n + 1); i++) {
    R(room[i]);
  }
  for (int i = (1); i < (n + 1); i++) {
    dp[i] = (room[i] == '0') + dp[i - 1];
  }
  int ans = n + 1;
  for (int i = (1); i < (n + 1); i++) {
    if (room[i] == '0') ans = min(ans, get_ans(i));
  }
  W(ans);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  for (int testcase = 1; testcase <= t; testcase++) {
    solve();
  }
  return 0;
}
