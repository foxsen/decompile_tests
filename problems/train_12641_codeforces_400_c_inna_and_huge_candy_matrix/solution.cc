#include <bits/stdc++.h>
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
const int MAXINT = 1111 * 1111 * 1111;
const long long MAXLINT = MAXINT * 1ll * MAXINT;
const long double EPS = 1e-10;
using namespace std;
int n, m, x, y, z, p;
int a, b;
void reverse_left() {
  int aa = a, bb = b;
  a = m - b + 1;
  b = aa;
  swap(n, m);
}
void reverse_middle() { b = m - b + 1; }
void reverse_right() {
  int aa = a, bb = b;
  b = n - a + 1;
  a = bb;
  swap(n, m);
}
void solve() {
  cin >> n >> m >> x >> y >> z >> p;
  int N = n, M = m;
  x %= 4;
  z %= 4;
  y %= 2;
  while (p--) {
    n = N;
    m = M;
    cin >> a >> b;
    for (int i = 0; i < x; i++) reverse_right();
    for (int i = 0; i < y; i++) reverse_middle();
    for (int i = 0; i < z; i++) reverse_left();
    cout << a << ' ' << b << endl;
  }
}
int main() { solve(); }
