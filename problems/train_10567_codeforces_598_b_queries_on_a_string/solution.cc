#include <bits/stdc++.h>
using namespace std;
long long n;
string s, f;
int main() {
  cin >> s >> n;
  if (s.length() == 1) {
    cout << s << endl;
    return 0;
  }
  for (int j = 1; j <= n; j++) {
    int l, r, k;
    cin >> l >> r >> k;
    k %= (r - l + 1);
    l--;
    for (int i = 0; i < l; i++) f += s[i];
    for (int i = r - k; i < r; i++) f += s[i];
    for (int i = l; i < r - k; i++) f += s[i];
    for (int i = r; i < s.length(); i++) f += s[i];
    s = f;
    f = "";
  }
  cout << s;
  return 0;
}
