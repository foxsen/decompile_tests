#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  if (n % 3 != 0) {
    cout << 0 << endl;
    return 0;
  }
  n /= 3;
  long long ans = 0;
  for (long long ab = 2; ab * ab * ab <= n; ab++)
    if (n % ab == 0)
      for (long long a = 1; 2 * a <= ab; a++) {
        long long b = ab - a;
        long long A = 1, B = ab, C = a * b - n / ab, D = B * B - 4 * A * C;
        if (D >= 0) {
          long long sD = (long long)(sqrt(max(0.0, D + 0.0)));
          if (sD * sD == D && sD - B > 0 && (sD - B) % (2 * A) == 0) {
            long long c = (sD - B) / (2 * A);
            if (c >= b) {
              if (a == b && b == c)
                ans++;
              else if (a == b || b == c)
                ans += 3;
              else
                ans += 6;
            }
          }
        }
      }
  cout << ans << endl;
  return 0;
}
