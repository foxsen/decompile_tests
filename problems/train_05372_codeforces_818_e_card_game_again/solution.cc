#include <bits/stdc++.h>
const double eps = 1e-10;
const float epsf = 1e-6;
using namespace std;
inline long long int __gcd(long long int a, long long int b) {
  if (a == 0 || b == 0) {
    return max(a, b);
  }
  long long int tempa, tempb;
  while (1) {
    if (a % b == 0)
      return b;
    else {
      tempa = a;
      tempb = b;
      a = tempb;
      b = tempa % tempb;
    }
  }
}
inline int compfloat(float& x, float& y) {
  if (fabs(x - y) < epsf)
    return 0;
  else if (x - y > 0)
    return 1;
  return -1;
}
inline int compdouble(double x, double y) {
  if (fabs(x - y) < eps)
    return 0;
  else if (x - y > 0)
    return 1;
  else
    return -1;
}
bool prime(long long int k) {
  for (long long int i = 2; i * i <= k; i++)
    if (k % i == 0) {
      return false;
    }
  return true;
}
void pdash(int n = 1) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 30; j++) {
      cout << "-";
    }
    cout << "\n";
  }
}
long long int power(long long int x, long long int y) {
  long long int result = 1;
  while (y > 0) {
    if (y & 1) {
      result = (result * x);
    }
    y = y >> 1;
    x = (x * x);
  }
  return result;
}
long long int power(long long int x, long long int y, long long int z) {
  long long int result = 1;
  x = x % z;
  while (y > 0) {
    if (y & 1) {
      result = (result * x) % z;
    }
    y = y >> 1;
    x = (x * x) % z;
  }
  return result;
}
long long int modInverse(long long int n, long long int p) {
  return power(n, p - 2, p);
}
long long int nCrF(long long int n, long long int r, long long int p) {
  if (n == 0 and r == 0) return 1;
  if (n == 0 || r > n) return 0;
  if (r == 0) return 1;
  long long int f[n + 1];
  f[0] = 1;
  for (long long int i = 1; i <= n; i++) f[i] = f[i - 1] * i % p;
  return (f[n] * modInverse(f[r], p) % p * modInverse(f[n - r], p) % p) % p;
}
void cordinate_compression(vector<int>& v) {
  vector<int> p = v;
  sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());
  for (int i = 0; i < (int)((v).size()); i++)
    v[i] = (int)(lower_bound(p.begin(), p.end(), v[i]) - p.begin());
}
long long int k;
struct segtree {
  int n;
  int N;
  vector<long long int> st;
  long long int k;
  void build(vector<long long int>& arr) {
    n = (int)((arr).size());
    N = ceil(log2(n));
    N = 1 << N;
    st = vector<long long int>(2 * N, 1);
    for (int i = 0; i < n; i++) st[i + N] = (arr[i]) % k;
    for (int i = N - 1; i > 0; i--) st[i] = (st[i << 1] * st[(i << 1) | 1]) % k;
  }
  long long int queries2(int qs, int qe, int ss, int se, int si) {
    if (ss > se || ss > qe || qs > se) return 1;
    if (ss >= qs && se <= qe) return st[si];
    return (queries2(qs, qe, ss, (ss + se) >> 1, si << 1) *
            queries2(qs, qe, ((ss + se) >> 1) + 1, se, (si << 1) | 1)) %
           k;
  }
  long long int queries(int qs, int qe) {
    return queries2(qs, qe, 0, N - 1, 1);
  }
  void update2(int qs, int qe, int diff, int ss, int se, int si) {
    if (ss > se || qs > se || qe < ss) return;
    if (!(ss ^ se)) {
      st[si] += diff;
      return;
    }
    update2(qs, qe, diff, ss, (ss + se) >> 1, si << 1);
    update2(qs, qe, diff, ((ss + se) >> 1) + 1, se, si << 1 | 1);
    st[si] = st[si << 1] + st[(si << 1) | 1];
  }
  void update(int qs, int qe, int diff) { update2(qs, qe, diff, 0, N - 1, 1); }
};
void solve() {
  long long int n, k;
  cin >> n >> k;
  segtree s;
  s.k = k;
  vector<long long int> vec(n);
  for (int i = 0; i < n; i++) cin >> vec[i];
  s.build(vec);
  long long int ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    int l = 0, r = i, mid;
    while (r - l > 1) {
      mid = (l + r) / 2;
      if (s.queries(mid, i) == 0) {
        l = mid;
      } else
        r = mid;
    }
    if (s.queries(r, i) == 0) {
      ans += (r + 1);
    } else if (s.queries(l, i) == 0) {
      ans += (l + 1);
    }
  }
  cout << ans << "\n";
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
}
