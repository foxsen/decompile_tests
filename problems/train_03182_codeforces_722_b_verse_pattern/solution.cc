#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n, a[105];
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  string t;
  getline(cin, t);
  for (int ii = 1; ii <= n; ii++) {
    string s;
    getline(cin, s);
    int m = s.length(), c = 0;
    for (int i = 0; i <= m - 1; i++) {
      if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
          s[i] == 'u' || s[i] == 'y')
        c++;
    }
    if (c != a[ii]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
