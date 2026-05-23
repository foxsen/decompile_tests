#include <bits/stdc++.h>
const int sz = 2 * 1e5 + 9, mod = 1e6 + 3;
using namespace std;
string s[1000];
int main() {
  s['>'] = "1000";
  s['<'] = "1001";
  s['+'] = "1010";
  s['-'] = "1011";
  s['.'] = "1100";
  s[','] = "1101";
  s['['] = "1110";
  s[']'] = "1111";
  string r, x;
  cin >> x;
  long long res = 0, c = 0;
  for (int i = 0; i < x.size(); i++) r += s[x[i]];
  for (int i = r.size() - 1, j = 0; i >= 0; i--, j++) {
    long long sm = 1;
    c = r[i] - '0';
    if (!c) continue;
    for (long long k = 0; k < j; k++) sm = ((sm % mod) * 2) % mod;
    res = (res % mod + sm % mod) % mod;
  }
  cout << res;
  return 0;
}
