#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.1415926535897932384626433832795l;
template <typename T>
inline auto sqr(T x) -> decltype(x * x) {
  return x * x;
}
template <typename T1, typename T2>
inline bool umx(T1& a, T2 b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T1, typename T2>
inline bool umn(T1& a, T2 b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
const int N = 150100;
struct Input {
  int n;
  int p[N];
  int t[N];
  bool read() {
    if (scanf("%d", &n) != 1) {
      return 0;
    }
    for (int i = int(0); i < int(n); ++i) {
      scanf("%d", &p[i]);
    }
    for (int i = int(0); i < int(n); ++i) {
      scanf("%d", &t[i]);
    }
    return 1;
  }
  void init(const Input& input) { *this = input; }
};
struct Data : Input {
  double ans;
  void write() { cout << ans << endl; }
  virtual void solve() {}
  virtual void clear() { *this = Data(); }
};
const double eps = 1e-10;
struct tree {
  int n;
  double t[N + 1];
  tree() {}
  tree(int n_) : n(n_) { memset(t, 0, sizeof t); }
  void clear() { memset(t, 0, sizeof(t)); }
  double get(int x) {
    if (x < 0) return 0.0;
    x++;
    double res = 0;
    for (; x; x &= (x - 1)) {
      umx(res, t[x]);
    }
    return res;
  }
  void upd(int x, double val) {
    ;
    for (++x; x < N + 1; x = (x | (x - 1)) + 1) {
      umx(t[x], val);
    }
  }
};
struct Solution : Data {
  int idx[N];
  long long T;
  int num[N];
  double f(int i, double x, double t) { return p[i] * (1 - x * (t / T)); }
  tree fen;
  bool check(long double m) {
    long long curt = 0;
    fen.clear();
    for (int i = 0; i < n;) {
      int j = i;
      long long tekt = 0;
      ;
      for (;
           j < n && 1ll * p[idx[i]] * t[idx[j]] == 1ll * p[idx[j]] * t[idx[i]];
           ++j) {
        tekt += t[idx[j]];
      };
      double mx = 0;
      for (int k = i; k < j;) {
        int nk = k;
        for (; nk < j && p[idx[nk]] == p[idx[k]]; ++nk)
          ;
        for (int ii = k; ii < nk; ++ii) {
          ;
          if (max(mx, fen.get(num[idx[ii]] - 1)) > f(idx[ii], m, curt + tekt)) {
            return 0;
          }
        }
        for (int ii = k; ii < nk; ++ii) {
          umx(mx, f(idx[ii], m, curt + t[idx[ii]]));
        }
        k = nk;
      }
      for (int k = i; k < j; ++k) {
        fen.upd(num[idx[k]], f(idx[k], m, curt + t[idx[k]]));
      }
      curt += tekt;
      i = j;
    }
    return 1;
  }
  void solve() {
    T = 0;
    for (int i = int(0); i < int(n); ++i) {
      T += t[i];
    }
    for (int i = int(0); i < int(n); ++i) {
      idx[i] = i;
    }
    sort(idx, idx + n, [&](int i, int j) { return p[i] < p[j]; });
    int cnt = 0;
    for (int i = 0; i < n;) {
      int j = i;
      for (; j < n && p[idx[i]] == p[idx[j]]; ++j)
        ;
      for (int k = i; k < j; ++k) {
        num[idx[k]] = cnt;
      }
      cnt++;
      i = j;
    }
    sort(idx, idx + n, [&](int i, int j) {
      return (1ll * p[i] * t[j] > 1ll * p[j] * t[i]) ||
             (1ll * p[i] * t[j] == 1ll * p[j] * t[i] && p[i] < p[j]);
    });
    long double l = 0, r = 1;
    for (int i = int(0); i < int(50); ++i) {
      ;
      long double m = (l + r) / 2;
      if (check(m)) {
        l = m;
      } else {
        r = m;
      }
    }
    ans = (l + r) / 2;
  }
  void clear() { *this = Solution(); }
};
Solution sol;
int main() {
  cout.setf(ios::showpoint | ios::fixed);
  cout.precision(20);
  sol.read();
  sol.solve();
  sol.write();
  return 0;
}
