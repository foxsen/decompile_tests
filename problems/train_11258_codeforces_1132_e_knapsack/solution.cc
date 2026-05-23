#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const int N = 2e5 + 10;
int main() {
  long long n;
  long long cnt[10];
  cin >> n;
  for (int i = 1; i <= 8; i++) cin >> cnt[i];
  long long ans = 0;
  for (int i1 = 0; i1 < 10; i1++) {
    for (int i2 = 0; i2 < 10; i2++) {
      for (int i3 = 0; i3 < 10; i3++) {
        for (int i4 = 0; i4 < 10; i4++) {
          for (int i5 = 0; i5 < 10; i5++) {
            for (int i6 = 0; i6 < 10; i6++) {
              for (int i7 = 0; i7 < 10; i7++) {
                int a[10] = {0, i1, i2, i3, i4, i5, i6, i7};
                long long b[10];
                int flag = 0;
                long long rest = n;
                for (int i = 1; i <= 7; i++) {
                  b[i] = min(cnt[i], rest / i);
                  rest -= b[i] * i;
                  if (b[i] < a[i]) {
                    flag = 1;
                    break;
                  }
                  rest += a[i] * i;
                }
                if (flag) continue;
                long long o = min(cnt[8], rest / 8);
                rest -= o * 8;
                ans = max(ans, n - rest);
              }
            }
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
