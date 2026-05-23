#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265358979323846;
const double SQRT2 = 1.41421356237;
const double EPS = 1e-9;
const float SQRT2F = (float)SQRT2;
const int INF = 1e9;
const long long INF64 = 1e18;
template <class T>
const T sqr(const T &x) {
  return x * x;
}
template <class T>
const T &min(const T &a, const T &b, const T &c) {
  return min(min(a, b), c);
}
template <class T>
const T &max(const T &a, const T &b, const T &c) {
  return max(max(a, b), c);
}
inline void yesno(bool y) { cout << (y ? "YES\n" : "NO\n"); }
inline void yes_stop(bool y) {
  if (y) {
    yesno(1);
    exit(0);
  }
}
inline void no_stop(bool y) {
  if (!y) {
    yesno(0);
    exit(0);
  }
}
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int sgn(int x) { return (x > 0) - (x < 0); }
ostream &operator<<(ostream &os, const pair<int, int> &ip) {
  return os << "(" << ip.first << "," << ip.second << ")";
}
class IManip {
 public:
  virtual void write(ostream &) const {}
};
template <class It>
class ManipRangePrinter : public IManip {
 private:
  const It b, e;

 public:
  ManipRangePrinter(It _b, It _e) : b(_b), e(_e) {}
  void write(ostream &os) const {
    It g = b;
    if (g != e) os << *g;
    for (++g; g != e; ++g) {
      os << " " << *g;
    }
  }
  It begin() { return b; }
  It end() { return e; }
};
class indent : public IManip {
 private:
  const int c;

 public:
  indent(int c) : c(c) {}
  void write(ostream &os) const {
    for (int i = 0; i < c; ++i) os << " ";
  }
};
ostream &operator<<(ostream &os, const IManip &man) {
  man.write(os);
  return os;
}
template <class It>
ManipRangePrinter<It> range(It b, It e) {
  return ManipRangePrinter<It>(b, e);
}
struct Edge {
  int to, w;
  bool operator<(const Edge &x) const {
    if (to == x.to) return w < x.w;
    return to < x.to;
  }
};
int q;
int t[100500], x[100500], c[100500];
long long len[100500];
int getOn(long long idx) {
  int i = upper_bound(len, len + q, idx) - len;
  if (t[i] == 1) {
    return x[i];
  } else {
    int loc = (idx - len[i - 1]) % x[i];
    return getOn(loc);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> q;
  cin >> t[0];
  cin >> x[0];
  len[0] = 1;
  for (int i = 1; i < q; ++i) {
    cin >> t[i];
    if (t[i] == 1) {
      cin >> x[i];
      len[i] = len[i - 1] + 1;
    } else {
      cin >> x[i] >> c[i];
      len[i] = len[i - 1] + x[i] * c[i];
    }
  }
  len[q] = len[q - 1];
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    long long z;
    cin >> z;
    cout << getOn(z - 1) << " ";
  }
  if (n == -1) {
    for (int i = 0; i < len[q]; ++i) {
      cout << getOn(i) << " ";
    }
  }
  cout << "\n";
  return 0;
}
