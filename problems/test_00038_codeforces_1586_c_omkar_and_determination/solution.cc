#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
string s[N];
int d[N];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> s[i];
  for (int i = 1; i <= m; i++)
    for (int j = 2; j <= n; j++)
      if (s[j][i - 1] == 'X' && s[j - 1][i] == 'X') {
        d[i] = 1;
        continue;
      }
  for (int i = 1; i <= m; i++) d[i] += d[i - 1];
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (d[r - 1] - d[l - 1])
      puts("NO");
    else
      puts("YES");
  }
  return 0;
}
