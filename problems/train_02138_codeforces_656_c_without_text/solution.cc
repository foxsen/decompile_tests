#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  int ans = 0;
  getline(cin, str);
  int len = str.length();
  for (int i = 0; i <= len - 1; i++) {
    if (isupper(str[i])) {
      ans += str[i] - 64;
    }
    if (islower(str[i])) {
      ans -= str[i] - 96;
    }
  }
  cout << ans << endl;
  return 0;
}
