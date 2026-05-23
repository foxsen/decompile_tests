#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
template <class T>
class Fenwick {
 private:
 public:
  vector<T> sum;
  int siz;
  Fenwick() {}
  Fenwick(int _siz) {
    siz = _siz;
    sum.resize(_siz);
  }
  void update(int x, T d) {
    for (int i = x; i < siz; i = i | (i + 1)) sum[i] += d;
  }
  T query(int x) {
    T ret = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1) ret += sum[i];
    return ret;
  }
  int kth(T k) {
    T cnt = 0;
    int ret = -1;
    for (int i = log2(siz); ~i; --i) {
      ret += 1 << i;
      if (ret >= siz - 1 || cnt + sum[ret] >= k + 1)
        ret -= 1 << i;
      else
        cnt += sum[ret];
    }
    return ret + 1;
  }
};
int n, a[100010];
void solve() {
  n = read();
  for (int i = 1; i <= n; ++i) a[i] = read();
  long long ans = 1e18;
  do {
    queue<int> q0, q1;
    for (int i = 1; i <= n; ++i) {
      if (a[i] % 2 == 0)
        q0.push(i);
      else
        q1.push(i);
    }
    Fenwick<long long> bit(n + 1);
    for (int i = 1; i <= n; ++i) bit.update(i, 1);
    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
      if (i % 2 == 0) {
        if (q0.empty()) {
          sum = 1e18;
          break;
        }
        int x = q0.front();
        q0.pop();
        int rk = bit.query(x);
        sum += rk - 1;
        bit.update(x, -1);
      } else {
        if (q1.empty()) {
          sum = 1e18;
          break;
        }
        int x = q1.front();
        q1.pop();
        int rk = bit.query(x);
        sum += rk - 1;
        bit.update(x, -1);
      }
    }
    ans = min(ans, sum);
  } while (0);
  do {
    queue<int> q0, q1;
    for (int i = 1; i <= n; ++i) {
      if (a[i] % 2 == 1)
        q0.push(i);
      else
        q1.push(i);
    }
    Fenwick<long long> bit(n + 1);
    for (int i = 1; i <= n; ++i) bit.update(i, 1);
    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
      if (i % 2 == 0) {
        if (q0.empty()) {
          sum = 1e18;
          break;
        }
        int x = q0.front();
        q0.pop();
        int rk = bit.query(x);
        sum += rk - 1;
        bit.update(x, -1);
      } else {
        if (q1.empty()) {
          sum = 1e18;
          break;
        }
        int x = q1.front();
        q1.pop();
        int rk = bit.query(x);
        sum += rk - 1;
        bit.update(x, -1);
      }
    }
    ans = min(ans, sum);
  } while (0);
  if (ans == 1e18) ans = -1;
  cout << ans << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
