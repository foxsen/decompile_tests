#include <bits/stdc++.h>
using namespace std;
int a[28];
bool check(string s) {
  for (int i = 0; i < s.size() / 2; i++)
    if (s[i] != s[s.size() - i - 1]) return false;
  return true;
}
int main() {
  string s;
  cin >> s;
  for (auto i : s) a[i - 'a']++;
  int mx = 0;
  for (auto i : a) mx = max(i, mx);
  if (s.size() % 2 == 0) {
    if (mx == s.size()) {
      cout << "Impossible\n";
      return 0;
    }
  } else {
    if (mx >= s.size() - 1) {
      cout << "Impossible\n";
      return 0;
    }
  }
  for (int i = 0; i < s.size(); i++) {
    string s1, s2, r;
    s1 = s.substr(0, i + 1);
    s2 = s.substr(i + 1, s.size() - i - 1);
    r = s2 + s1;
    if (check(r) && r != s) {
      cout << 1;
      return 0;
    }
  }
  cout << 2;
}
