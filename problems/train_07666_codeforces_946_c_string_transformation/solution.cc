#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int maxn = 2 * 1e5 + 123;
string s;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> s;
  int n = s.size();
  int p = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] - 'a' <= p) {
      s[i] = 'a' + p;
      p++;
    }
    if (p == 26) break;
  }
  if (p < 26) {
    cout << -1;
  } else
    cout << s;
  return 0;
}
