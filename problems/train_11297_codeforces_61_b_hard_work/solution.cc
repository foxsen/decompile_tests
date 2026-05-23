#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y) {
  for (int v = max(x, y); v >= 1; v--) {
    if (x % v == 0 && y % v == 0) return v;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  string t1, t2, t3, a, b, c, d;
  int x;
  cin >> a >> b >> c;
  for (int i = 0; i < a.length(); i++) {
    if (a[i] != '_' && a[i] != ';' && a[i] != '-') t1 += tolower(a[i]);
  }
  for (int i = 0; i < b.length(); i++) {
    if (b[i] != '_' && b[i] != ';' && b[i] != '-') t2 += tolower(b[i]);
  }
  for (int i = 0; i < c.length(); i++) {
    if (c[i] != '_' && c[i] != ';' && c[i] != '-') t3 += tolower(c[i]);
  }
  a = t1 + t2 + t3;
  b = t1 + t3 + t2;
  c = t2 + t1 + t3;
  string a1, b1, c1;
  a1 = t2 + t3 + t1;
  b1 = t3 + t1 + t2;
  c1 = t3 + t2 + t1;
  cin >> x;
  string d2 = "";
  for (int an = 0; an < x; an++) {
    cin >> d;
    for (int tt = 0; tt < d.length(); tt++) {
      if (d[tt] != '_' && d[tt] != ';' && d[tt] != '-') d2 += tolower(d[tt]);
    }
    if (d2 == a || d2 == b || d2 == c || d2 == a1 || d2 == b1 || d2 == c1)
      cout << "ACC" << endl;
    else
      cout << "WA" << endl;
    d2.clear();
  }
}
