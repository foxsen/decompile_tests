#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 100;
const int M = 10000 + 100;
int a[N], psum[N], ssum[N], mx[N];
int mxtot[M];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    for (int j = 1; j <= k; ++j) cin >> a[j];
    psum[0] = 0;
    for (int j = 1; j <= k; ++j) psum[j] = psum[j - 1] + a[j];
    ssum[k + 1] = 0;
    for (int j = k; j >= 0; --j) ssum[j] = ssum[j + 1] + a[j];
    for (int j = 0; j <= k; ++j) mx[j] = 0;
    for (int l = 0; l <= k; ++l) {
      int cnt = l;
      for (int r = k + 1; r > 0 and l < r; --r, ++cnt) {
        mx[cnt] = max(mx[cnt], psum[l] + ssum[r]);
      }
    }
    for (int j = m; j >= 0; --j) {
      for (int p = 1; p <= k and j - p >= 0; ++p) {
        mxtot[j] = max(mxtot[j], mxtot[j - p] + mx[p]);
      }
    }
  }
  cout << mxtot[m] << '\n';
  return 0;
}
