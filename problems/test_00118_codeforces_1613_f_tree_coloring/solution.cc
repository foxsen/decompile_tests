#include <bits/stdc++.h>
using namespace std;
const int G = 3;
const int Gi = 332748118;
long long su(long long a, long long b) {
  a += b;
  return (a >= 998244353) ? a - 998244353 : a;
}
int r[300000], lim;
long long ksm(long long a, long long p) {
  long long res = 1;
  while (p) {
    if (p & 1) {
      res = res * a % 998244353;
    }
    a = a * a % 998244353;
    p >>= 1;
  }
  return res;
}
void ntt(vector<long long> &A, int type) {
  for (int i = 0; i <= lim - 1; ++i) {
    if (i < r[i]) swap(A[i], A[r[i]]);
  }
  for (int mid = 1; mid <= lim - 1; mid <<= 1) {
    long long Wn = ksm(type == 1 ? G : Gi, (998244353 - 1) / (mid << 1));
    for (int j = 0; j <= lim - 1; j += (mid << 1)) {
      long long w = 1;
      for (int k = 0; k <= mid - 1; ++k, w = (w * Wn) % 998244353) {
        int x = A[j + k];
        int y = w * A[j + mid + k] % 998244353;
        A[j + k] = su(x, y);
        A[j + mid + k] = su(x, 998244353 - y);
      }
    }
  }
  if (type == -1) {
    long long tmp = ksm(lim, 998244353 - 2);
    for (int i = 0; i <= lim - 1; ++i) {
      A[i] = A[i] * tmp % 998244353;
    }
  }
}
vector<long long> operator*(vector<long long> A, vector<long long> B) {
  int len = A.size() + B.size() - 1;
  lim = 1;
  while (lim <= len) lim <<= 1;
  for (int i = 0; i <= lim - 1; ++i) {
    r[i] = (r[i >> 1] >> 1) | ((i & 1) * (lim >> 1));
  }
  A.resize(lim);
  B.resize(lim);
  ntt(A, 1);
  ntt(B, 1);
  for (int i = 0; i <= lim - 1; ++i) {
    A[i] = A[i] * B[i] % 998244353;
  }
  ntt(A, -1);
  A.resize(len);
  return A;
}
int i, j, k, n, m, t, a[250005];
long long jc[250005];
vector<long long> v;
vector<long long> work(int l, int r) {
  if (l == r) {
    return {1, a[l] - (l != 1)};
  }
  return work(l, (l + r) / 2) * work((l + r) / 2 + 1, r);
}
int main() {
  jc[0] = 1;
  for (i = 1; i <= 250000; i++) {
    jc[i] = jc[i - 1] * i % 998244353;
  }
  ios::sync_with_stdio(0);
  cin >> n;
  for (i = 1; i < n; i++) {
    cin >> j >> k;
    a[j]++;
    a[k]++;
  }
  v = work(1, n);
  long long res = 0;
  for (i = n - 1; i >= 0; i--) {
    if (i & 1)
      res = su(res, 998244353 - v[i] * jc[n - i] % 998244353);
    else
      res = su(res, v[i] * jc[n - i] % 998244353);
  }
  cout << res;
}
