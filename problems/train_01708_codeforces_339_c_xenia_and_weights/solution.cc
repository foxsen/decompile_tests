#include <bits/stdc++.h>
using namespace std;
template <class t>
inline t read(t &x) {
  char c = getchar();
  bool f = 0;
  x = 0;
  while (!isdigit(c)) f |= c == '-', c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  if (f) x = -x;
  return x;
}
template <class t>
inline void write(t x) {
  if (x < 0)
    putchar('-'), write(-x);
  else {
    if (x > 9) write(x / 10);
    putchar('0' + x % 10);
  }
}
int ans[1005], m;
char s[11];
void dfs(int last, int num, int x) {
  if (x == m + 1) {
    puts("YES");
    for (int i = 1; i <= m; i++) write(ans[i]), putchar(' ');
    exit(0);
  }
  for (int i = num + 1; i <= 10; i++)
    if (i != last && s[i] == '1') ans[x] = i, dfs(i, i - num, x + 1);
}
signed main() {
  scanf("%s", s + 1);
  read(m);
  dfs(0, 0, 1);
  puts("NO");
}
