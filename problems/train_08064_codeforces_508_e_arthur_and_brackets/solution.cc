#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool read(T &x) {
  int c = getchar();
  int sgn = 1;
  while (~c && c<'0' | c> '9') {
    if (c == '-') sgn = -1;
    c = getchar();
  }
  for (x = 0; ~c && '0' <= c && c <= '9'; c = getchar()) x = x * 10 + c - '0';
  x *= sgn;
  return ~c;
}
struct debugger {
  template <typename T>
  debugger &operator,(const T &v) {
    cerr << v << "    ";
    return *this;
  }
} dbg;
template <class T>
void __stl_print__(T &x) {
  cerr << "[";
  for (__typeof((x).end()) i = (x).begin(); i != (x).end(); ++i)
    cerr << (i != x.begin() ? ", " : "") << *i;
  cerr << "]" << endl;
}
template <class T, class U>
inline T max(T &a, U &b) {
  return a > b ? a : b;
}
template <class T, class U>
inline T min(T &a, U &b) {
  return a < b ? a : b;
}
template <class T, class U>
inline T swap(T &a, U &b) {
  T tmp = a;
  a = b;
  b = tmp;
}
const long long INF = (1ll) << 50;
const int mx = 1e5 + 7;
const int mod = 1000000007;
const double pi = 2 * acos(0.0);
int EQ(double d) {
  if (fabs(d) < 1e-7) return 0;
  return d > 1e-7 ? 1 : -1;
}
bool vis[602][602];
bool dp[602][602];
vector<pair<int, int> > v;
int n;
bool call(int rem, int pos) {
  if (rem == 0) return dp[rem][pos] = 1;
  if (rem < 0) return 0;
  if (pos >= n) return 0;
  if (vis[rem][pos]) return dp[rem][pos];
  vis[rem][pos] = 1;
  for (int i = v[pos].first; i <= v[pos].second; i += 2) {
    int nxt = (i + 1) / 2;
    if (call(nxt - 1, pos + 1) && call(rem - nxt, pos + nxt)) {
      return dp[rem][pos] = 1;
    }
  }
  return 0;
}
char ch[1202];
int lf, rt;
void make(int rem, int pos) {
  if (rem == 0) return;
  for (int i = v[pos].first; i <= v[pos].second; i += 2) {
    int nxt = (i + 1) / 2;
    if (dp[nxt - 1][pos + 1] && dp[rem - nxt][pos + nxt]) {
      ch[lf] = '(';
      ch[lf + i] = ')';
      int tl = lf, tr = rt;
      lf++;
      rt = lf + i - 1;
      make(nxt - 1, pos + 1);
      lf = tl + i + 1;
      make(rem - nxt, pos + nxt);
      break;
    }
  }
}
int main() {
  n = ({
    int a;
    read(a);
    a;
  });
  for (__typeof((n)-1) i = (0); i <= ((n)-1); ++i) {
    int x = ({
      int a;
      read(a);
      a;
    }),
        y = ({
          int a;
          read(a);
          a;
        });
    x += !(x % 2);
    y -= !(y % 2);
    if (x > y) {
      cout << "IMPOSSIBLE" << endl;
      exit(0);
    }
    v.push_back(pair<int, int>(x, y));
  }
  if (call(n, 0)) {
    lf = 0, rt = 2 * n - 1;
    make(n, 0);
    ch[2 * n] = 0;
    printf("%s\n", ch);
  } else
    cout << "IMPOSSIBLE" << endl;
}
