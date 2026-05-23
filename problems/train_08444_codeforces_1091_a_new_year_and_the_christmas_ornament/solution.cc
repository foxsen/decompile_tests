#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2 * 1e5 + 5;
const long long INF = 1e8 + 5;
const long long MOD = 1e9 + 7;
long long N;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long Y, B, R;
  cin >> Y >> B >> R;
  long long ans = 0;
  if (B >= R - 1 and Y >= R - 2) {
    ans = max(ans, R + R - 1 + R - 2);
  }
  if (Y >= B - 1 and B + 1 <= R) {
    ans = max(ans, B - 1 + B + B + 1);
  }
  if (B >= Y + 1 and R >= Y + 2) {
    ans = max(ans, Y + Y + 1 + Y + 2);
  }
  cout << ans << endl;
  return 0;
}
