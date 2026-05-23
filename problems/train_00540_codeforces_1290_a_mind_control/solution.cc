#include <bits/stdc++.h>
using namespace std;
template <typename so>
void read(so &x) {
  x = 0;
  char c;
  long long dem = 0;
  for (c = getchar(); c < '0' || c > '9'; c = getchar()) {
    dem++;
    if (dem == 100) return;
  }
  for (; c >= '0' && c <= '9'; c = getchar()) {
    x = x * 10 + c - '0';
  }
}
const long long MaxN = 1e6 + 1e5;
const long long mod = 1e9 + 7;
long long n, m, k;
long long a[MaxN];
long long gtln = 0;
void input() {
  cin >> n >> m >> k;
  k = min(m - 1, k);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  gtln = 0;
  for (long long i = 0; i <= k; i++) {
    long long trai = i, phai = n - k + i;
    long long range = n - m;
    long long gtnn = INT_MAX;
    for (long long j = trai; j < phai - range; j++) {
      gtnn = min(gtnn, max(a[j], a[j + range]));
    }
    gtln = max(gtnn, gtln);
  }
  cout << gtln << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long test = 1;
  cin >> test;
  while (test--) {
    input();
  }
}
