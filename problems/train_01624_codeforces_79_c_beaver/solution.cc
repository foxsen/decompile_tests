#include <bits/stdc++.h>
using namespace std;
template <typename T>
void print(vector<T>& v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << ' ';
  }
  cout << '\n';
}
vector<int> z_function(string s) {
  int n = (int)s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  int n = s.length();
  int q;
  cin >> q;
  string sr = s;
  reverse(sr.begin(), sr.end());
  vector<int> v(n, n + 1);
  while (q--) {
    string t;
    cin >> t;
    int l = t.length();
    for (int i = 0; i < n; i++) {
      if (i + l > n) break;
      if (s.substr(i, l) == t) {
        v[i + l - 1] = min(v[i + l - 1], l);
      }
    }
  }
  int maxlen = (v[0] == 1) ? 0 : 1;
  int index = 0;
  int ans = maxlen;
  for (int i = 1; i < n; i++) {
    int len = min(v[i] - 1, ans + 1);
    if (len > maxlen) {
      maxlen = len;
      index = i - len + 1;
    }
    ans = len;
  }
  cout << maxlen << ' ' << index << '\n';
}
