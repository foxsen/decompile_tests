#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
const int MOD = 1e9 + 7;
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  short int t;
  cin >> t;
  string s;
  while (t--) {
    cin >> s;
    short int i, x = 0, y = 0, z = 0;
    vector<short int> v(26, 0);
    for (i = 0; i < s.length(); i++) {
      v[s[i] - 'a']++;
    }
    for (i = 0; i < 26; i++) {
      if (v[i] >= 2) {
        x++;
        y++;
      } else if (v[i] == 1) {
        z++;
      }
    }
    x += (z / 2);
    y += (z / 2);
    cout << min(x, y) << "\n";
  }
  return 0;
}
