#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e6 + 10;
char a[maxn];
int main() {
  int tt;
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", a + 1);
    bool t[3] = {0, 0, 0};
    int n = strlen(a + 1);
    for (int i = 1; i <= n - 1; i++) {
      if (a[i] != '?' && a[i] == a[i + 1]) {
        printf("-1\n");
        goto out;
      }
    }
    for (int i = 1; i <= n; i++) {
      t[0] = t[1] = t[2] = 0;
      if (a[i - 1] && a[i - 1] != '?') {
        t[a[i - 1] - 'a'] = 1;
      }
      if (a[i + 1] && a[i + 1] != '?') {
        t[a[i + 1] - 'a'] = 1;
      }
      if (a[i] == '?') {
        for (int j = 0; j < 3; j++) {
          if (!t[j]) {
            a[i] = 'a' + j;
            break;
          }
        }
      }
    }
    printf("%s\n", a + 1);
  out:;
  }
}
