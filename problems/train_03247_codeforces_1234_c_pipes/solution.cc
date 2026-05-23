#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7, N = 2e5 + 5;
long long n;
bool b[N][2];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int k = 0; k < n; k++) {
      char tmp;
      cin >> tmp;
      if (tmp == '1' || tmp == '2')
        b[k][0] = 1;
      else
        b[k][0] = 0;
    }
    for (int k = 0; k < n; k++) {
      char tmp;
      cin >> tmp;
      if (tmp == '1' || tmp == '2')
        b[k][1] = 1;
      else
        b[k][1] = 0;
    }
    bool ans = 1;
    long long ud = 0;
    for (int k = 0; k < n; k++) {
      if (b[k][ud])
        continue;
      else {
        if (b[k][(ud == 1 ? 0 : 1)]) {
          ans = 0;
          break;
        } else {
          ud = (ud == 1 ? 0 : 1);
        }
      }
    }
    cout << ((ans && (ud == 1)) ? "YES" : "NO") << '\n';
  }
  return 0;
}
