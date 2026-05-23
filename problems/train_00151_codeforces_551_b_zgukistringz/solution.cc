#include <bits/stdc++.h>
using namespace std;
const int LIM = 26;
const int INF = 1e+9;
struct str {
  int a[LIM];
  str(string s) {
    fill(a, a + LIM, 0);
    for (int i = 0; i < (int)s.length(); ++i) ++a[s[i] - 'a'];
  }
};
string sa, sb, sc;
int check(str& a, int cur, str& b, str& c) {
  int ans = INF;
  for (int i = 0; i < LIM; ++i) {
    if (a.a[i] < b.a[i] * cur)
      ans = -1;
    else if (c.a[i] != 0)
      ans = min(ans, (a.a[i] - cur * b.a[i]) / c.a[i]);
  }
  if (ans != -1) return ans + cur;
  return ans;
}
void print(str& a, int cur, str& b, str& c) {
  for (int i = 0; i < cur; ++i) cout << sb;
  int sec = check(a, cur, b, c) - cur;
  for (int i = 0; i < sec; ++i) cout << sc;
  for (int i = 0; i < LIM; ++i) {
    a.a[i] -= b.a[i] * cur;
    a.a[i] -= c.a[i] * sec;
    for (int j = 0; j < a.a[i]; ++j) cout << (char)('a' + i);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> sa >> sb >> sc;
  str a(sa), b(sb), c(sc);
  int ans = -1, step = -1, cur = 0;
  while (true) {
    int cur_a = check(a, cur, b, c);
    if (cur_a == -1) break;
    if (ans == -1 || ans < cur_a) {
      ans = cur_a;
      step = cur;
    }
    ++cur;
  }
  print(a, step, b, c);
  return 0;
}
