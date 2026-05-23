#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, k, s[1010], d[1010], ans = 0, minn[1010];
  cin >> m >> k;
  for (int i = 0; i < m; i++) cin >> d[i], ans += d[i];
  for (int i = 0; i < m; i++) cin >> s[i];
  int l = 0, r = 0, maxx = 0;
  for (int i = 0; i < m; i++) {
    l += s[i];
    r += d[i];
    if (s[i] > maxx) maxx = s[i];
    if (r > l)
      ans += (int)(ceil((double)(r - l) / (double)maxx)) * k,
          l += (int)(ceil((double)(r - l) / (double)maxx)) * maxx;
  }
  cout << ans << endl;
  return 0;
}
