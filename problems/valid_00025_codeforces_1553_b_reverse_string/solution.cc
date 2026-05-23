#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int q;
  cin >> q;
  while (q--) {
    string s, t;
    cin >> s >> t;
    int i, j;
    bool kt = 0;
    for (i = 0; i < s.size(); ++i) {
      string s1 = s.substr(0, i + 1), s2 = s.substr(0, i);
      reverse(s2.begin(), s2.end());
      s1 += s2;
      if (s1.find(t) != -1) {
        kt = 1;
        break;
      }
    }
    if (kt == 1)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
  return 0;
}
