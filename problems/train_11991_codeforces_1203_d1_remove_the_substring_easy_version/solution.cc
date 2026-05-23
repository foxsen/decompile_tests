#include <bits/stdc++.h>
using namespace std;
string s, s1;
bool check(string ans) {
  int pos = 0;
  for (int i = 0; i < ans.size(); i++) {
    if (ans[i] == s1[pos]) {
      pos++;
    }
  }
  if (pos == s1.size())
    return true;
  else
    return false;
}
int main() {
  cin >> s >> s1;
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    for (int j = 0; j < s.size() - i + 1; j++) {
      string res = "";
      for (int k = 0; k < i; k++) res += s[k];
      for (int k = j + i; k < s.size(); k++) res += s[k];
      if (check(res)) {
        ans = max(ans, j);
      }
    }
  }
  cout << ans << endl;
}
