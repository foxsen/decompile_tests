#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
int len[MAXN], q[MAXN];
bool query[MAXN];
char str[MAXN][MAXN];
int getline(char *s) {
  int cnt = 0;
  while (isspace(s[cnt] = getchar()))
    ;
  for (++cnt; (s[cnt] = getchar()) != EOF && s[cnt] != '\n'; ++cnt)
    ;
  return cnt;
}
int main() {
  int n, m;
  char buf[MAXN];
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) len[i] = getline(str[i]);
  for (int i = 1; i <= m; ++i) scanf("%d", &q[i]), query[q[i]] = true;
  int length = len[q[1]];
  for (int i = 2; i <= m; ++i)
    if (length != len[q[i]]) {
      puts("No");
      return 0;
    }
  bool isok = true;
  for (int i = 0; i < length; ++i) {
    bool same = true;
    for (int j = 2; j <= m; ++j)
      if (str[q[1]][i] != str[q[j]][i]) {
        same = false;
        break;
      }
    buf[i] = same ? str[q[1]][i] : '?';
  }
  buf[length] = 0;
  for (int i = 1; i <= n; ++i) {
    if (query[i] || length != len[i]) continue;
    bool matchable = true;
    for (int j = 0; j < length; ++j) {
      if (buf[j] != '?' && buf[j] != str[i][j]) {
        matchable = false;
        break;
      }
    }
    if (matchable) {
      isok = false;
      break;
    }
  }
  if (isok) {
    puts("Yes");
    puts(buf);
  } else {
    puts("No");
  }
}
