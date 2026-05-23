#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
long long n, m;
long long pp(long long t, long long p) {
  if (p == 0) return 1;
  if (p == 1) return t;
  long long res = pp(t, p / 2);
  res = (res * res) % m;
  if (p % 2) res = (res * t) % m;
  return res;
}
int main() {
  cin >> n >> m;
  long long p = pp(3, n);
  long long res = (p + m - 1) % m;
  cout << res << endl;
  return 0;
}
