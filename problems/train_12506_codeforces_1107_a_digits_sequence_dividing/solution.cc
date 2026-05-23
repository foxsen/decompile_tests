#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  string s;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    cin >> s;
    if (t == 2) {
      if (s[0] >= s[1]) {
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
        cout << 2 << endl;
        cout << s[0] << " " << s[1] << endl;
      }
    } else {
      cout << "YES" << endl;
      cout << 2 << endl;
      cout << s[0] << " " << s.erase(0, 1) << endl;
    }
  }
}
