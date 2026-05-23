#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, j, k, l, a, b, ans = 0, c;
  cin >> n;
  for (i = 1; i <= n; i++) {
    for (j = i; j <= n; j++) {
      a = i * i;
      b = j * j;
      c = (long long int)sqrt(a + b);
      if (c <= n) {
        if ((a + b) == c * c) {
          ans++;
        }
      } else {
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
