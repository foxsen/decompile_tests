#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int w = 0, wo = 0, ans = 0;
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'o') {
      wo += w;
    } else if (i > 0 && s[i - 1] == 'v') {
      w++;
      ans += wo;
    }
  }
  cout << ans << endl;
  return 0;
}
