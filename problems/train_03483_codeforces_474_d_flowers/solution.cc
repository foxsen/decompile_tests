#include <bits/stdc++.h>
using namespace std;
int v[100010];
int som[100010];
int t, k;
void pd() {
  for (int i = 0; i < 100010 - 5; i++) {
    if (i < k)
      v[i] = 1;
    else {
      v[i] = v[i - 1] + v[i - k];
      if (v[i] >= 1000000007) v[i] -= 1000000007;
    }
  }
}
int main() {
  cin >> t >> k;
  int ans;
  int a, b;
  pd();
  ans = 0;
  for (int j = 0; j < 100010 - 7; j++) {
    ans += v[j];
    if (ans >= 1000000007) ans -= 1000000007;
    som[j] = ans;
  }
  for (int i = 0; i < t; i++) {
    cin >> a >> b;
    ans = som[b] - som[a] + v[a];
    if (ans < 0)
      ans += 1000000007;
    else if (ans >= 1000000007)
      ans -= 1000000007;
    cout << ans << endl;
  }
  return 0;
}
