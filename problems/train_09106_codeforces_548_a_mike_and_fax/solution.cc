#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int k;
  cin >> s >> k;
  if (s.size() % k != 0) {
    cout << "NO" << endl;
    return 0;
  }
  int len = s.size() / k;
  string a;
  vector<string> wow;
  for (int i = (0); i < int(s.size()); ++i) {
    a += s[i];
    if ((i + 1) % len == 0) {
      wow.push_back(a);
      a = "";
    }
  }
  for (int i = (0); i < int(wow.size()); ++i) {
    for (int j = (0); j < int(len); ++j) {
      if (wow[i][j] != wow[i][len - j - 1]) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
  return 0;
}
