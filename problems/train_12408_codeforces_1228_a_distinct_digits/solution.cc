#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int l, r;
  cin >> l >> r;
  for (int i = l; i <= r; i++) {
    string s = to_string(i);
    sort((s).begin(), (s).end());
    bool flag = true;
    for (int i = 1; i < (int)s.size(); i++)
      if (s[i] == s[i - 1]) flag = false;
    if (flag) {
      cout << i << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
}
