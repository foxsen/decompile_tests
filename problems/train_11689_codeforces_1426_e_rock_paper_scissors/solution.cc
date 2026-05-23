#include <bits/stdc++.h>
using namespace std;
int go(int a, int b, int c, int d) {
  int ans = 0;
  if (a <= b) return ans;
  a -= b;
  if (a <= c) return ans;
  a -= c;
  ans += a;
  return ans;
}
int go2(int& a, int& b) {
  int ans = 0;
  if (a <= b) {
    ans += a;
    b -= a;
    a = 0;
    return ans;
  }
  ans += b;
  a -= b;
  b = 0;
  return ans;
}
void solve() {
  int n;
  cin >> n;
  int a1, b1, c1, a2, b2, c2;
  cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
  int val1 = 0, val2 = 0;
  val1 += go(a1, a2, c2, b2);
  val1 += go(b1, b2, a2, c2);
  val1 += go(c1, c2, b2, a2);
  val2 += go2(a1, b2);
  val2 += go2(b1, c2);
  val2 += go2(c1, a2);
  cout << val1 << " " << val2 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  solve();
  return 0;
}
