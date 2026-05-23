#include <bits/stdc++.h>
using namespace std;
int n, m;
bool valid(int x, int y) {
  if (x > -1 && y > -1 && x < n && y < m)
    return true;
  else
    return false;
}
int main() {
  int n;
  int a, b;
  int c, d;
  int e, f;
  cin >> n;
  cin >> a >> b;
  cin >> c >> d;
  cin >> e >> f;
  int x, y, z;
  x = a;
  y = c;
  z = e;
  a = b - a;
  c = d - c;
  e = f - e;
  int det = 0;
  det = n - x - y - z;
  x += min(det, a);
  det = n - x - y - z;
  y += min(det, c);
  det = n - x - y - z;
  z += min(det, e);
  cout << x << " " << y << " " << z << endl;
}
