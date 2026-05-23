#include <bits/stdc++.h>
using namespace std;
double pi = 2 * acos(0.0);
const long long int INF = 1e9 + 7;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a / gcd(a, b)) * b;
}
long long int power(long long int x, long long int y) {
  long long int res = 1;
  x = x;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
void WetPitch() {
  long long int n;
  cin >> n;
  vector<long long int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  bool flag = false;
  bool slag = false;
  vector<long long int> ty(n);
  for (int i = 0; i < n; i++) {
    cin >> ty[i];
    if (ty[i] == 0) flag = true;
    if (ty[i] == 1) slag = true;
  }
  if ((flag == true && slag == true) || (is_sorted(v.begin(), v.end()))) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int tst;
  tst = 1;
  cin >> tst;
  int p = 1;
  while (tst--) {
    WetPitch();
  }
  return 0;
}
