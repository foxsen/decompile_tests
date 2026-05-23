#include <bits/stdc++.h>
using namespace std;
long long int MOD = (1e9) + 7;
inline void fastIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}
int main() {
  fastIO();
  int n, l, r, dif, ans = 0;
  cin >> n >> l >> r >> dif;
  vector<int> problems(n);
  for (int i = 0; i < n; i++) {
    cin >> problems[i];
  }
  for (int i = 0; i < pow(2, n); i++) {
    int bitmask = i, sum = 0, minn = 1e9, maxx = 0, num = 0;
    for (int j = 0; j < n; j++) {
      if (bitmask & (1 << (j))) {
        sum += problems[j], num++;
        minn = min(minn, problems[j]);
        maxx = max(maxx, problems[j]);
      }
    }
    bool valid = (sum >= l && sum <= r) && (maxx - minn >= dif) && (num >= 2);
    if (valid) ans++;
  }
  cout << ans << endl;
}
