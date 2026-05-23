#include <bits/stdc++.h>
using namespace std;
template <class a, class b>
ostream& operator<<(ostream& os, const pair<a, b>& p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  if (!v.size())
    os << "]";
  else
    for (int i = 0; i < v.size(); ++i) os << v[i] << ",]"[i == v.size() - 1];
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const set<T>& s) {
  os << "{";
  if (!s.size())
    os << "}";
  else
    for (auto x : s) os << x << ",}"[x == *s.rbegin()];
  return os;
}
void printr(ostream& os) { os << '\n'; }
template <class T, class... Args>
void printr(ostream& os, const T& t, const Args&... args) {
  os << t;
  if (sizeof...(args)) os << " ";
  printr(os, args...);
}
template <class T>
void read(T& x) {
  cin >> x;
}
template <class T, class... Args>
void read(T& t, Args&... args) {
  read(t), read(args...);
}
template <class T>
void readarray(T* A, int n) {
  for (__typeof(0) i = (0), _end = (n), _step = 1 - 2 * ((0) > (n)); i != _end;
       i += _step)
    read(A[i]);
}
void dbgr(ostream& os) { os << endl; }
template <class T, class... Args>
void dbgr(ostream& os, const T& t, const Args&... args) {
  os << t;
  if (sizeof...(args)) os << ", ";
  dbgr(os, args...);
}
template <class T>
T min(const vector<T>& v) {
  return *min_element(v.begin(), v.end());
}
template <class T>
T max(const vector<T>& v) {
  return *max_element(v.begin(), v.end());
}
long long pw(long long a, long long k = 998244353 - 2) {
  long long ans = 1;
  for (a %= 998244353; k; k >>= 1) {
    if (k & 1) ans = ans * a % 998244353;
    a = a * a % 998244353;
  }
  return ans;
}
int n, m;
int x[15];
char a[15][10050];
int pos[10050], p[10050];
long long c[10050];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int _;
  read(_);
  while (_--) {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> x[i];
    for (int i = 0; i < n; ++i) cin >> a[i];
    long long ans = -1e18;
    for (int s = 0; s < (1 << n); ++s) {
      long long sum = 0;
      for (int j = 0; j < m; ++j) c[j] = 0, pos[j] = j;
      for (int i = 0; i < n; ++i) {
        long long sgn = (s >> i & 1) ? 1 : -1;
        sum -= x[i] * sgn;
        for (int j = 0; j < m; ++j)
          if (a[i][j] == '1') c[j] += sgn;
      }
      sort(pos, pos + m, [&](int i, int j) { return c[i] < c[j]; });
      for (int j = 0; j < m; ++j) sum += (j + 1) * c[pos[j]];
      if (sum > ans) {
        ans = sum;
        for (int j = 0; j < m; ++j) p[pos[j]] = j + 1;
      }
    }
    for (int j = 0; j < m; ++j) cout << p[j] << " ";
    cout << endl;
  }
  return 0;
}
