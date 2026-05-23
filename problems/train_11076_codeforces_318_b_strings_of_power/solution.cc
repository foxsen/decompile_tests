#include <bits/stdc++.h>
const long long inf = 0x3f3f3f3f3f3f3f3f;
const long long maxn = 2e6 + 7;
using namespace std;
string h = "heavy", m = "metal";
string s;
long long pre[maxn], pree[maxn];
void solve() {
  int flag = 1, pl = 0, cnt = 0;
  while (~pl) {
    if (pl == 0) pl = -1;
    pl = s.find(h, pl + 1);
    if (~pl) pre[pl++]++;
  }
  pl = 0;
  while (~pl) {
    if (pl == 0) pl = -1;
    pl = s.find(m, pl + 1);
    if (~pl) pree[pl++]++;
  }
  for (int i = 1; i <= s.size(); i++)
    pree[i] += pree[i - 1], pre[i] += pre[i - 1];
  long long sum = 0, n = s.size() - 1;
  for (int i = 0; i < s.size(); i++) {
    if (pre[i] - pre[i - 1] == 1) {
      sum += (pree[n] - pree[i]);
    }
  }
  cout << sum << "\n";
}
int main() {
  cin >> s;
  solve();
}
