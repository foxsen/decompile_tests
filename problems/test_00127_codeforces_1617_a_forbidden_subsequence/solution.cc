#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    string s, t, st = "abc";
    cin >> s >> t;
    sort(s.begin(), s.end());
    long long int a1 = 0, b1 = 0, c1 = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'a') a1++;
      if (s[i] == 'b') b1++;
      if (s[i] == 'c') c1++;
    }
    if (a1 > 0 && b1 > 0 && c1 > 0) {
      for (int i = 0; i < a1; i++) cout << "a";
      if (t == "abc") {
        for (int i = 0; i < c1; i++) cout << "c";
        for (int i = 0; i < b1; i++) cout << "b";
      } else {
        for (int i = 0; i < b1; i++) cout << "b";
        for (int i = 0; i < c1; i++) cout << "c";
      }
      for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'a' || s[i] == 'b' || s[i] == 'c')
          continue;
        else
          cout << s[i];
      }
      cout << "\n";
      ;
    } else {
      cout << s << "\n";
      ;
    }
  }
  return 0;
}
