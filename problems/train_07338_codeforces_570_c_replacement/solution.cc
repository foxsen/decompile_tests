#include <bits/stdc++.h>
using namespace std;
int n, q;
int main() {
  string s;
  cin >> n >> q >> s;
  int l = 0, ans = 0;
  cout << endl;
  for (int i = 0; i < s.length(); i++)
    if (s[i] == '.')
      l++;
    else
      ans += (l > 0) ? (l - 1) : 0, l = 0;
  ans += (l > 0) ? (l - 1) : 0;
  while (q--) {
    int k;
    char ch;
    cin >> k >> ch, k--;
    if (ch == '.') {
      if (s[k] != '.') {
        s[k] = '.';
        if (s[k + 1] == '.') ans++;
        if (s[k - 1] == '.') ans++;
      }
    } else {
      if (s[k] == '.') {
        s[k] = ch;
        if (s[k + 1] == '.') ans--;
        if (s[k - 1] == '.') ans--;
      }
    }
    cout << ans << '\n';
  }
}
