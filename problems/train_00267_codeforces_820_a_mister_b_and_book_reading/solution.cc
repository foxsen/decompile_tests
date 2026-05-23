#include <bits/stdc++.h>
using namespace std;
int main() {
  int c, v0, v1, a, l;
  cin >> c >> v0 >> v1 >> a >> l;
  int ans = 1, t = 0, s = v0;
  t += s;
  while (t < c) {
    t -= l;
    if (s + a > v1)
      s = v1;
    else
      s += a;
    t += s;
    ans++;
  }
  cout << ans << endl;
}
