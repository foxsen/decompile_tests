#include <bits/stdc++.h>
using namespace std;
int n, a[110], ans;
char s[2][110];
inline int lowbit(int x) { return x & -x; }
int main() {
  scanf("%s%s", s[0] + 1, s[1] + 1);
  n = strlen(s[0] + 1);
  for (int i = 1; i <= n; i++)
    a[i] = ((s[0][i] == '0') << 1) + (s[1][i] == '0');
  for (int i = 1; i <= n; i++)
    if (a[i] == 3) {
      if (a[i - 1])
        ans++;
      else if (a[i + 1])
        ans++, a[i + 1] -= lowbit(a[i + 1]);
      a[i] = 0;
    }
  printf("%d", ans);
  return 0;
}
