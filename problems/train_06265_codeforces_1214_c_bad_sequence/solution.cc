#include <bits/stdc++.h>
using namespace std;
int f[300007];
int main() {
  int n;
  scanf("%d", &n);
  string s;
  cin >> s;
  s = '#' + s;
  for (auto i = (1); i <= (n); ++i) {
    if (s[i] == '(')
      f[i] = f[i - 1] + 1;
    else
      f[i] = f[i - 1] - 1;
  }
  if (f[n] != 0) {
    puts("No");
    return 0;
  }
  int mn = 0;
  for (auto i = (1); i <= (n); ++i) {
    mn = min(mn, f[i]);
  }
  if (mn >= -1)
    puts("Yes");
  else
    puts("No");
  return 0;
}
