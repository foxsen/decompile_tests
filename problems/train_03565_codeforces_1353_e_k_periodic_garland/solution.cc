#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cout.tie(NULL);
  ;
  long long tt = 1;
  cin >> tt;
  while (tt--) {
    long long n, k, j = 0, i = 0, ans = 0, fans = 1e9, pre = 0, c = 0, z = 0,
                    f = 1;
    cin >> n >> k;
    string s;
    cin >> s;
    for (auto x : s)
      if (x == '1') c++;
    for (long long i = 0; i < k; i++) {
      z = 0;
      for (long long j = i; j < n; j += k) {
        if (s[j] == '1') {
          z++;
        } else {
          z--;
        }
        z = max(z, 0ll);
        fans = min(c - z, fans);
      }
    }
    cout << max(fans, 0ll) << "\n";
  }
}
