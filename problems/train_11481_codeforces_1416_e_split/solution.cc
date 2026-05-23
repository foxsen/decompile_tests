#include <bits/stdc++.h>
using namespace std;
void read(long long &a) {
  a = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    a = (a << 1) + (a << 3) + (c ^ 48);
    c = getchar();
  }
}
const long long Maxn = 500000;
long long T;
struct Reverse_Set {
  long long left, right;
  set<long long> point;
  long long rev;
  long long base;
  void clear() {
    left = 1, right = 0;
    point.clear();
    rev = 1;
    base = 0;
  }
  void push_seg(long long x) {
    clear();
    right = x;
  }
  void push_point(long long x) {
    clear();
    point.insert(x);
  }
  void reverse(long long maxn) {
    base = maxn - base;
    left = maxn - left;
    right = maxn - right;
    swap(left, right);
    rev *= -1;
  }
  long long find_id(long long x) { return rev * (x - base); }
  long long find_val(long long x) { return base + x * rev; }
  void del(long long x) {
    right = min(right, x);
    if (point.empty()) {
      return;
    }
    if (rev == -1) {
      while (!point.empty() && find_val(*point.begin()) > x) {
        point.erase(point.begin());
      }
    } else {
      while (!point.empty() && find_val(*(--point.end())) > x) {
        point.erase(--point.end());
      }
    }
  }
  bool find_in(long long x) {
    if (left <= x && right >= x) {
      return 1;
    }
    if (point.count(find_id(x)) > 0) {
      return 1;
    }
    return 0;
  }
  void add_point(long long x) { point.insert(find_id(x)); }
  bool empty() { return left > right && point.empty(); }
} st;
long long n;
long long a[Maxn + 5];
void solve() {
  st.clear();
  read(n);
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    read(a[i]);
    st.del(a[i] - 1);
    if (!(a[i] & 1) && st.find_in(a[i] >> 1)) {
      st.push_point(a[i] >> 1);
      ans += 2;
    } else if (st.empty()) {
      if (!(a[i] & 1)) {
        ans++;
        st.push_point(a[i] >> 1);
      } else {
        st.push_seg(a[i] - 1);
      }
    } else {
      ans++;
      if (!(a[i] & 1)) {
        st.add_point(a[i] >> 1);
      }
    }
    st.reverse(a[i]);
  }
  printf("%lld\n", (n << 1) - ans);
}
signed main() {
  read(T);
  while (T--) {
    solve();
  }
  return 0;
}
