#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U>
ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << "(" << p.first << "," << p.second << ")";
  return o;
}
template <class T>
ostream& operator<<(ostream& o, const vector<T>& v) {
  o << "[";
  for (T t : v) {
    o << t << ",";
  }
  o << "]";
  return o;
}
const string OK = "YES", NG = "NO";
string solve() {
  int n, m;
  cin >> n >> m;
  vector<string> f(n);
  for (int(i) = 0; (i) < (int)(n); ++(i)) cin >> f[i];
  if (n % 3 == 0) {
    int r = 0, b = 0, g = 0;
    bool ok = true;
    for (int(i) = 0; (i) < (int)(3); ++(i)) {
      int s = n / 3 * i;
      char c = f[s][0];
      if (c == 'R')
        ++r;
      else if (c == 'G')
        ++g;
      else
        ++b;
      for (int j = s; j < s + n / 3; ++j) {
        for (int(k) = 0; (k) < (int)(m); ++(k))
          if (f[j][k] != c) ok = false;
      }
    }
    if (ok && r * b * g == 1) return OK;
  }
  if (m % 3 == 0) {
    int r = 0, b = 0, g = 0;
    bool ok = true;
    for (int(i) = 0; (i) < (int)(3); ++(i)) {
      int s = m / 3 * i;
      char c = f[0][s];
      if (c == 'R')
        ++r;
      else if (c == 'G')
        ++g;
      else
        ++b;
      for (int j = s; j < s + m / 3; ++j) {
        for (int(k) = 0; (k) < (int)(n); ++(k))
          if (f[k][j] != c) ok = false;
      }
    }
    if (ok && r * b * g == 1) return OK;
  }
  return NG;
}
int main() {
  cout << solve() << endl;
  return 0;
}
