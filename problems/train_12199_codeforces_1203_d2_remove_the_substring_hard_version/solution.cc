#include <bits/stdc++.h>
using namespace std;
string s, t;
int rig[200100], pos, rrr;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> s >> t;
  pos = s.size() - 1;
  for (int i = t.size() - 1; i >= 0; i--) {
    while (s[pos] != t[i]) pos--;
    rig[i] = pos;
    pos--;
  }
  int ans = 0;
  pos = 0;
  for (int i = 0; i < s.size(); i++) {
    rrr = s.size() - 1;
    if (pos < t.size()) rrr = rig[pos] - 1;
    ans = max(ans, rrr - i + 1);
    if (pos < t.size() && s[i] == t[pos]) pos++;
  }
  cout << ans << endl;
  return 0;
}
