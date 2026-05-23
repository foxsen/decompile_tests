#include <bits/stdc++.h>
using namespace std;
static const int INF = 500000000;
template <class T>
void debug(T a, T b) {
  for (; a != b; ++a) cerr << *a << ' ';
  cerr << endl;
}
int n;
int ar[100005];
const long long int mod = 1000000007;
struct segtree {
  long long int val[4000005];
  int n;
  void init(int n_) {
    n = 1;
    while (n < n_) n <<= 1;
    for (int i = 0; i < n * 2; ++i) val[i] = 0;
  }
  void set(int k, long long int a) {
    k += n - 1;
    val[k] = a;
    while (k > 0) {
      k = (k - 1) / 2;
      val[k] = (val[k * 2 + 1] + val[k * 2 + 2]) % mod;
    }
  }
  long long int get(int k) { return val[k + n - 1]; }
  long long int query(int a, int b, int i, int l, int r) {
    if (a <= l && r <= b) return val[i];
    if (b <= l || r <= a) return 0;
    int md = (l + r) >> 1;
    return (query(a, b, i * 2 + 1, l, md) + query(a, b, i * 2 + 2, md, r)) %
           mod;
  }
};
segtree seg;
int main() {
  seg.init(1000005);
  cin >> n;
  for (int i = 0; i < n; ++i) scanf("%d", &ar[i]);
  seg.set(0, 1);
  for (int i = 0; i < n; ++i) {
    long long int lower = seg.query(0, ar[i] + 1, 0, 0, seg.n);
    seg.set(ar[i], (lower * ar[i]) % mod);
  }
  long long int res = 0;
  for (int i = 0; i < 1000005; ++i) res += seg.get(i);
  res += mod - 1;
  res %= mod;
  cout << res << endl;
  return 0;
}
