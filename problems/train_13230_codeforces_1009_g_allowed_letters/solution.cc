#include <bits/stdc++.h>
using namespace std;
long long read() {
  char ch = getchar();
  long long x = 0;
  int op = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') op = -1;
  for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + ch - '0';
  return x * op;
}
int n, m, a[100005], b[100005][70], tmp[70], cnt[70];
char s[100005], s2[100005], ans[100005];
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  m = read();
  while (m--) {
    int k = read(), l;
    scanf("%s", s2 + 1);
    l = strlen(s2 + 1);
    for (int i = (1); i <= (l); i++) a[k] |= 1 << s2[i] - 'a';
  }
  for (int i = (1); i <= (n); i++)
    if (!a[i]) a[i] = (1 << 6) - 1;
  for (int i = (1); i <= (n); i++) {
    int x = s[i] - 'a';
    for (int j = (0); j <= ((1 << 6) - 1); j++)
      if (j >> x & 1) cnt[j]++;
  }
  for (int i = (n); i >= (1); i--)
    for (int j = (0); j <= ((1 << 6) - 1); j++) {
      if ((j & a[i]) == a[i]) tmp[j]++;
      b[i][j] = tmp[j];
    }
  for (int p = (1); p <= (n - 1); p++) {
    bool flag = 0;
    for (int i = (0); i <= (5); i++)
      if (cnt[1 << i] && (a[p] >> i & 1)) {
        bool chk = 1;
        for (int j = (0); j <= ((1 << 6) - 1); j++)
          if (cnt[j] - (j >> i & 1) < b[p + 1][j]) {
            chk = 0;
            break;
          }
        if (chk) {
          flag = 1;
          ans[p] = i + 'a';
          for (int j = (0); j <= ((1 << 6) - 1); j++)
            if (j >> i & 1) cnt[j]--;
        }
      }
    if (!flag) {
      puts("Impossible");
      exit(0);
    }
  }
  bool flag = 0;
  for (int i = (0); i <= (5); i++)
    if (cnt[1 << i] && (a[n] >> i & 1)) {
      flag = 1;
      ans[n] = i + 'a';
      break;
    }
  if (!flag) {
    puts("Impossible");
    exit(0);
  }
  ans[n + 1] = '\0';
  puts(ans + 1);
  return 0;
}
