#include <bits/stdc++.h>
using namespace std;
void readi(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = v * 10 + c - '0';
  while (isdigit(c = getchar())) v = v * 10 + c - '0';
  x = v * f;
}
void readll(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = v * 10 + c - '0';
  while (isdigit(c = getchar())) v = v * 10 + c - '0';
  x = v * f;
}
void readc(char &x) {
  char c;
  while ((c = getchar()) == ' ')
    ;
  x = c;
}
void writes(string s) { puts(s.c_str()); }
void writeln() { writes(""); }
void writei(int x) {
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
void writell(long long x) {
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
int lst[(1 << 15) + 7], cur[(1 << 15) + 7], fa[(1 << 15) + 7];
int n, i, j, m, ans;
string s;
int find(int x) {
  if (x == fa[x]) return x;
  return fa[x] = find(fa[x]);
}
int merge(int x, int y) {
  if (find(x) == find(y)) return 0;
  fa[find(x)] = find(y);
  return 1;
}
int main() {
  ios::sync_with_stdio(false);
  ;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    cin >> s;
    s = " " + s;
    for (j = 1; j <= m / 4; j++) {
      if (s[j] >= 'A') s[j] -= 'A' - '9' - 1;
    }
    for (j = 1; j <= m; j++) {
      int x = s[(j - 1) / 4 + 1] - '0';
      cur[j] = (bool)(x & (1 << (3 - (j - 1) % 4)));
      ans += cur[j];
    }
    for (j = m + 1; j <= m * 2; j++) {
      fa[j] = j;
    }
    for (j = 1; j <= m; j++) {
      if (lst[j] && cur[j]) {
        ans -= merge(j, j + m);
      }
    }
    for (j = 2; j <= m; j++) {
      if (cur[j - 1] && cur[j]) {
        ans -= merge(j + m - 1, j + m);
      }
    }
    for (j = 1; j <= m; j++) {
      lst[j] = cur[j];
      fa[j] = find(j + m) - m;
    }
  }
  cout << ans;
  return 0;
}
