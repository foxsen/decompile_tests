#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  ;
  long long s = 0;
  for (long long i = 0; i < n; i += 2) s += a[i];
  long long s1 = 0, s11 = 0;
  for (long long i = 1; i < n; i += 2) {
    if (a[i] - a[i - 1] + s1 > 0)
      s1 = a[i] - a[i - 1] + s1;
    else
      s1 = 0;
    if (s1 > s11) s11 = s1;
  }
  long long s2 = 0, s22 = 0;
  for (long long i = 1; i < n - 1; i += 2) {
    if (a[i] - a[i + 1] + s2 > 0)
      s2 = a[i] - a[i + 1] + s2;
    else
      s2 = 0;
    if (s2 > s22) s22 = s2;
  }
  s += max(s11, s22);
  cout << s << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
