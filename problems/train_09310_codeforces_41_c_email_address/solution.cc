#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int sl = s.length();
  string ans = "";
  ans += s[0];
  bool at = false;
  for (int i = 1; i < sl; i++) {
    if (at == false && (sl - i) > 2 && s.substr(i, 2) == "at")
      ans += '@', at = true, i++;
    else if ((sl - i) > 3 && s.substr(i, 3) == "dot")
      ans += ".", i += 2;
    else
      ans += s[i];
  }
  cout << ans << "\n";
  return 0;
}
