#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)2e5 + 5;
long long k, c[MAXN];
string s, t;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  while (cin >> k >> s >> t) {
    for (long long i = 0; i < k; ++i) c[i] = s[i] - 'a' + t[i] - 'a';
    for (long long i = k - 1; i > 0; --i)
      if (c[i] >= 26) c[i] -= 26, c[i - 1]++;
    for (long long i = 0; i < k; ++i)
      c[i + 1] += c[i] & 1 ? 26 : 0, cout << char(c[i] / 2 + 'a');
  }
}
