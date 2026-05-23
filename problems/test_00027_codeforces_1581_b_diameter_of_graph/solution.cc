#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
const double eps = 1e-6;
const int mod = 1e9 + 7;
int a[N];
long long get(long long n) { return n * (n + 1) / 2; }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, m, k;
    cin >> n >> m >> k;
    long long s = get(n - 1), first = n - 1, tk;
    if (m > s || m < first) {
      cout << "NO" << endl;
      continue;
    }
    if (m >= s)
      tk = 1;
    else
      tk = 2;
    if (n == 1 && m == 0) tk = 0;
    if (k - 1 > tk)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
