#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long LLinf = 0x3f3f3f3f3f3f3f3f;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10ll + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int maxn = 100000 + 10;
char s[maxn], t[maxn];
int sb[maxn], sc[maxn], fa[maxn];
int sbt[maxn], sct[maxn], fat[maxn];
int n, m;
int Q;
int a, b, c, d;
int db, dc, dbt, dct;
int len1, len2;
void build() {
  scanf("%s%s", s + 1, t + 1);
  n = strlen(s + 1);
  m = strlen(t + 1);
  for (int i = 1; i <= n; i++) {
    fa[i] = i + 1;
    sb[i] = sb[i - 1] + (s[i] == 'B' ? 1 : 0);
    sc[i] = sc[i - 1] + (s[i] == 'C' ? 1 : 0);
    if (s[i] == 'A') {
      if (s[i - 1] == 'A')
        fa[i] = fa[i - 1];
      else
        fa[i] = i;
    }
  }
  for (int i = 1; i <= m; i++) {
    fat[i] = i + 1;
    sbt[i] = sbt[i - 1] + (t[i] == 'B' ? 1 : 0);
    sct[i] = sct[i - 1] + (t[i] == 'C' ? 1 : 0);
    if (t[i] == 'A') {
      if (t[i - 1] == 'A')
        fat[i] = fat[i - 1];
      else
        fat[i] = i;
    }
  }
}
void solve() {
  scanf("%d", &Q);
  while (Q--) {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    db = sb[b] - sb[a - 1];
    dc = sc[b] - sc[a - 1];
    dbt = sbt[d] - sbt[c - 1];
    dct = sct[d] - sct[c - 1];
    if (db + dc < dbt + dct) {
      len1 = b - fa[b] + 1;
      len1 = min(len1, b - a + 1);
      len2 = d - fat[d] + 1;
      len2 = min(len2, d - c + 1);
      if (len1 < len2 || (len1 - 1 < len2) && (len1 == b - a + 1))
        printf("0");
      else if ((dbt + dct - db - dc) % 2 == 0)
        printf("1");
      else
        printf("0");
    } else if (db + dc > dbt + dct) {
      printf("0");
    } else {
      len1 = b - fa[b] + 1;
      len1 = min(len1, b - a + 1);
      len2 = d - fat[d] + 1;
      len2 = min(len2, d - c + 1);
      if (len1 >= len2 && (len1 - len2) % 3 == 0)
        printf("1");
      else
        printf("0");
    }
  }
  printf("\n");
}
int main() {
  build();
  solve();
  return 0;
}
