#include <bits/stdc++.h>
using namespace std;
const int INF = int(1e9);
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b, p;
    cin >> a >> b >> p;
    string s;
    cin >> s;
    int n = s.size();
    int ans = s.size();
    long long cost = 0;
    for (int i = n - 2; i >= 0;) {
      int j = i;
      while (j >= 0 && s[i] == s[j]) j--;
      if (s[i] == 'A')
        cost += (long long)a;
      else
        cost += (long long)b;
      if (cost <= p) ans = min(ans, j + 2);
      i = j;
    }
    cout << ans << '\n';
  }
  return 0;
}
