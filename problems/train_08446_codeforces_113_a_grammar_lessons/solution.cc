#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const long double eps = 1e-7;
const long double pi = 3.1415926535897932384626433832795;
long long pow_mod(long long a, long long n, long long mod) {
  long long res = 1;
  while (n) {
    if (n & 1) res *= a;
    res %= mod;
    a *= a;
    a %= mod;
    n >>= 1;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
char buf[200000];
int zak(string a) {
  int n = a.size();
  string d;
  if (n >= 4) {
    d = "";
    for (int i = 4; i > 0; i--) d += a[n - i];
  }
  if (n >= 4 && d == "lios") return 1;
  if (n >= 5) {
    d = "";
    for (int i = 5; i > 0; i--) d += a[n - i];
  }
  if (a.size() >= 5 && d == "liala") return 2;
  if (n >= 3) {
    d = "";
    for (int i = 3; i > 0; i--) d += a[n - i];
  }
  if (a.size() >= 3 && d == "etr") return 3;
  if (n >= 4) {
    d = "";
    for (int i = 4; i > 0; i--) d += a[n - i];
  }
  if (a.size() >= 4 && d == "etra") return 4;
  if (n >= 6) {
    d = "";
    for (int i = 6; i > 0; i--) d += a[n - i];
  }
  if (a.size() >= 6 && d == "initis") return 5;
  if (a.size() >= 6 && d == "inites") return 6;
  return 0;
}
int main() {
  gets(buf);
  string s = buf;
  s += ' ';
  string d = "";
  vector<int> g, gg;
  int k = 0;
  for (int i = 0; i < s.size(); i++)
    if (s[i] == ' ') {
      int x = zak(d);
      k++;
      gg.push_back(x);
      g.push_back((x + 1) / 2);
      if (x == 0) {
        cout << "NO" << endl;
        return 0;
      }
      d = "";
    } else
      d += s[i];
  int p = 0;
  if (k == 1) {
    cout << "YES" << endl;
    return 0;
  }
  for (int i = 0; i < g.size(); i++)
    if (g[i] == 2) p++;
  if (p != 1) {
    cout << "NO" << endl;
    return 0;
  }
  for (int i = 1; i < g.size(); i++)
    if (g[i] < g[i - 1] || gg[i] % 2 != gg[i - 1] % 2) {
      cout << "NO" << endl;
      return 0;
    }
  cout << "YES" << endl;
  return 0;
}
