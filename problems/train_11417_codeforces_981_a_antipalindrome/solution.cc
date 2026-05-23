#include <bits/stdc++.h>
using namespace std;
const int N = (int)(1e5 + 5);
const int LIMIT = 1000000;
bool ispal(string &s, int l, int r) {
  while (l < r) {
    if (s[l] != s[r]) return false;
    ++l, --r;
  }
  return true;
}
string s;
int main() {
  ios::sync_with_stdio(false);
  cin.tie();
  cin >> s;
  for (int l = s.length(); l >= 0; l--)
    for (int i = 0; i < s.length() - l + 1; i++)
      if (!ispal(s, i, i + l - 1)) {
        cout << l << endl;
        return 0;
      }
  cout << 0 << endl;
  return 0;
}
