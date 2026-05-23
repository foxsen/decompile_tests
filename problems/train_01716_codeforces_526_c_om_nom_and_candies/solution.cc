#include <bits/stdc++.h>
using namespace std;
long long int x, h1, h2, w1, w2, mx;
long long int ans, i;
int main() {
  cin >> x >> h1 >> h2 >> w1 >> w2;
  if (max(w1, w2) < 100000) {
    if (h1 * 1.0 / w1 < h2 * 1.0 / w2) {
      swap(h1, h2);
      swap(w1, w2);
    }
    for (i = 0; i <= 100000; i++) {
      if (x >= i * w2) ans = max(ans, ((x - i * w2) / w1) * h1 + h2 * i);
    }
    cout << ans << '\n';
  } else {
    if (w1 < w2) {
      swap(h1, h2);
      swap(w1, w2);
    }
    for (i = 0; i <= x; i += w1) {
      ans = max(ans, (i / w1) * h1 + ((x - i) / w2) * h2);
    }
    cout << ans << '\n';
  }
}
