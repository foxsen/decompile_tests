#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
int t1[N << 1];
vector<int> t2[N << 1];
void add(vector<int> &v, int x) {
  for (int &a : v)
    if (a & -a & x) x ^= a;
  if (x == 0) return;
  for (int &a : v)
    if (x & -x & a) a ^= x;
  v.push_back(x);
}
vector<int> operator+(vector<int> a, vector<int> b) {
  if (a.size() < b.size()) a.swap(b);
  for (int x : b) add(a, x);
  return a;
}
int a[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int q;
  cin >> q;
  auto updValue = [&](int l, int r, int v) {
    l += n - 1;
    r += n;
    for (; l < r; l >>= 1, r >>= 1) {
      if (l & 1) t1[l++] ^= v;
      if (r & 1) t1[--r] ^= v;
    }
  };
  auto getValue = [&](int p) {
    int ans = 0;
    for (p += n - 1; p; p >>= 1) ans ^= t1[p];
    return ans;
  };
  auto updGauss = [&](int p, int v) {
    t2[p += n - 1].clear();
    add(t2[p], v);
    for (; p > 1; p >>= 1) t2[p >> 1] = t2[p] + t2[p ^ 1];
  };
  auto getGauss = [&](int l, int r) {
    vector<int> C;
    add(C, getValue(l));
    l += n;
    r += n;
    for (; l < r; l >>= 1, r >>= 1) {
      if (l & 1) C = C + t2[l++];
      if (r & 1) C = C + t2[--r];
    }
    return (1 << C.size());
  };
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    updValue(i, i, a[i]);
    updGauss(i, a[i] ^ a[i - 1]);
  }
  for (int i = n; i >= 1; --i) a[i] ^= a[i - 1];
  for (int i = 1; i <= q; ++i) {
    int t;
    cin >> t;
    int l;
    cin >> l;
    int r;
    cin >> r;
    if (t == 1) {
      int k;
      cin >> k;
      updValue(l, r, k);
      ++r;
      updGauss(l, a[l] ^= k);
      updGauss(r, a[r] ^= k);
      continue;
    }
    if (t == 2) cout << getGauss(l, r) << "\n";
  }
}
