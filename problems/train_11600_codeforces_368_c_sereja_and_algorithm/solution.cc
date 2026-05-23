#include <bits/stdc++.h>
using namespace std;
const int MAXN = 190001;
const int MAXM = 11111;
const int INF = 0x3f3f3f3f;
const long long mod = 1000000007;
int n, m, l, r;
int a[MAXN];
int b[MAXN];
int c[MAXN];
char s[MAXN];
int main() {
  cin >> s + 1;
  n = strlen(s + 1);
  memset(a, 0, sizeof(a)), memset(b, 0, sizeof(b)), memset(c, 0, sizeof(c));
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'x') a[i] = 1;
    if (s[i] == 'y') b[i] = 1;
    if (s[i] == 'z') c[i] = 1;
  }
  for (int i = 1; i <= n; i++)
    a[i] = a[i] + a[i - 1], b[i] = b[i] + b[i - 1], c[i] = c[i] + c[i - 1];
  cin >> m;
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &l, &r);
    if (r - l + 1 <= 2) {
      printf("YES\n");
      continue;
    }
    int x = a[r] - a[l - 1];
    int y = b[r] - b[l - 1];
    int z = c[r] - c[l - 1];
    int minn = min(x, min(y, z));
    int maxx = max(x, max(y, z));
    if (maxx - minn <= 1)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
