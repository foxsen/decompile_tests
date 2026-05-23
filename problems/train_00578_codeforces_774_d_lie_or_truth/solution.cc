#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, l, r;
  cin >> n >> l >> r;
  std::vector<long long> v(n);
  std::vector<long long> v1(n);
  long long f = 1;
  for (long long i = 0; i < n; ++i) {
    cin >> v[i];
  }
  for (long long i = 0; i < n; ++i) {
    cin >> v1[i];
  }
  for (long long i = 0; i < n; ++i) {
    if ((v[i] != v1[i]) && (i < l - 1 || i > r - 1)) {
      f = 0;
      break;
    }
  }
  if (f) {
    cout << "TRUTH";
  } else {
    cout << "LIE";
  }
  return 0;
}
