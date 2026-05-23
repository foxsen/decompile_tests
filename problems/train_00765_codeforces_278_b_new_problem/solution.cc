#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  std::ios::sync_with_stdio(false);
  long long n;
  string s;
  map<string, bool> maap;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int k = 0; k < s.size(); k++) {
      for (int h = k; h < s.size(); h++) {
        maap[s.substr(k, h - k + 1)]++;
      }
    }
  }
  s.clear();
  s = "a";
  while (maap[s]) {
    s[s.size() - 1]++;
    if (s[s.size() - 1] > 'z' && s.size() == 1) {
      s = "aa";
    } else if (s.size() == 2 && s[s.size() - 1] > 'z') {
      s[0]++;
      s[s.size() - 1] = 'a';
      if (s[0] > 'z') s = "aaa";
    }
  }
  cout << s << endl;
  return 0;
}
