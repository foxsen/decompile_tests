#include <bits/stdc++.h>
using namespace std;
int sumstr[26];
pair<string, string> to_get(string s) {
  reverse(s.begin(), s.end());
  string zc;
  for (int i = 0; i < s.size(); i++) {
    if (!sumstr[s[i] - 'a']) {
      zc += s[i];
    }
    sumstr[s[i] - 'a']++;
  }
  int chushilenth = 0;
  int m = zc.size();
  for (int i = 0; i < m; i++) {
    chushilenth += sumstr[zc[i] - 'a'] / (m - i);
  }
  reverse(zc.begin(), zc.end());
  return {string(s.rbegin(), s.rbegin() + chushilenth), zc};
}
string check(pair<string, string> s) {
  string chushi = s.first;
  string zc = s.second;
  string tt;
  tt += chushi;
  for (int i = 0; i < zc.size(); i++) {
    string kk;
    for (int j = 0; j < chushi.size(); j++) {
      if (chushi[j] != zc[i]) kk += chushi[j];
    }
    tt += kk;
    chushi = kk;
  }
  return tt;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    memset(sumstr, 0, sizeof sumstr);
    string s;
    cin >> s;
    pair<string, string> get = to_get(s);
    if (check(get) == s) {
      cout << get.first << ' ' << get.second << endl;
    } else
      cout << -1 << endl;
  }
  return 0;
}
