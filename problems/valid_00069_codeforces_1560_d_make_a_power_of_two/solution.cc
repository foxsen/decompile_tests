#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const int N = 100010, INF = 0x3f3f3f3f;
int T;
long long l[N], cnt = 0;
string s[N];
void solve() {
  long long t;
  cin >> t;
  string str;
  while (t) {
    str += t % 10 + '0';
    t /= 10;
  }
  reverse(str.begin(), str.end());
  int ans = INF;
  string tt;
  for (int i = 1; i <= cnt; i++) {
    int res = 0;
    int k = 0, p = 0;
    for (auto j : s[i]) {
      int flag = 1;
      for (int z = p; z < str.size(); z++)
        if (j == str[z] && k < str.size()) {
          p = z + 1;
          flag = 0;
          k++;
          break;
        }
      if (flag) break;
    }
    if (k == s[i].size())
      res = str.size() - s[i].size();
    else if (k == str.size())
      res = s[i].size() - k;
    else
      res = str.size() - k + s[i].size() - k;
    ans = min(ans, res);
  }
  cout << ans << '\n';
}
int main(void) {
  clock_t c1 = clock();
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  l[1] = 1;
  cnt = 1;
  for (int i = 2; l[i - 1] * 2 <= 1e18; i++) l[i] = l[i - 1] << 1, cnt++;
  for (int i = 1; i <= cnt; i++) {
    string temp;
    while (l[i]) {
      temp += l[i] % 10 + '0';
      l[i] /= 10;
    }
    reverse(temp.begin(), temp.end());
    s[i] = temp;
  }
  T = 1;
  cin >> T;
  while (T--) solve();
  cerr << "Time Used:" << clock() - c1 << "ms" << '\n';
  return 0;
}
