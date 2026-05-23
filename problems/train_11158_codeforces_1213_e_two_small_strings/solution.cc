#include <bits/stdc++.h>
using namespace std;
bool check(const string &s, const string &t, const string &res) {
  for (int i = 1; i < res.size(); ++i)
    if ((res[i] == s[1] && res[i - 1] == s[0]) ||
        (res[i] == t[1] && res[i - 1] == t[0]))
      return false;
  return true;
}
int main() {
  bool f = false;
  int n;
  string s, t, per = "abc";
  cin >> n >> s >> t;
  do {
    string res1, res2;
    for (int i = 0; i < n; ++i) res1 += per;
    for (int i = 0; i < n; ++i) res2 += per[0];
    for (int i = 0; i < n; ++i) res2 += per[1];
    for (int i = 0; i < n; ++i) res2 += per[2];
    if (check(s, t, res1)) {
      cout << "YES\n" << res1;
      f = true;
      break;
    }
    if (check(s, t, res2)) {
      cout << "YES\n" << res2;
      f = true;
      break;
    }
  } while (next_permutation(per.begin(), per.end()));
  if (!f) cout << "NO";
  return 0;
}
