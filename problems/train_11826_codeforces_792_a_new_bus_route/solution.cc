#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<long long>;
using vl = vector<long long>;
using pii = pair<long long, long long>;
using pll = pair<long long, long long>;
const long long DX[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0},
                DY[9] = {-1, 0, 1, 0, -1, 1, 1, -1, 0};
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (auto i = begin(v); i != end(v); ++i)
    os << *i << (i == end(v) - 1 ? "" : "\n");
  return os;
}
template <class T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto i = begin(v); i != end(v); ++i) is >> *i;
  return is;
}
template <class T>
istream &operator>>(istream &is, pair<T, T> &p) {
  is >> p.first >> p.second;
  return is;
}
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
struct before_main_function {
  before_main_function() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
  }
} before_main_function;
signed main() {
  long long N;
  cin >> N;
  vi a(N);
  cin >> a;
  sort(begin(a), end(a));
  long long min = (1001001001001001001ll);
  for (long long i = 1, i_len = (long long)(((long long)a.size())); i < i_len;
       ++i) {
    chmin(min, a[i] - a[i - 1]);
  }
  long long ans = 0;
  for (long long i = 1, i_len = (long long)(((long long)a.size())); i < i_len;
       ++i) {
    if (a[i] - a[i - 1] == min) ans++;
  }
  cout << min << " " << ans << endl;
  return 0;
}
