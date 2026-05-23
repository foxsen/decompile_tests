#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
using namespace std;
const bool d[3][2][2] = {
    {
        {false, true},
        {true, false},
    },
    {
        {true, false},
        {true, true},
    },
    {
        {true, true},
        {false, true},
    },
};
bitset<2020> f[2020];
bool c[2020][2][2], o[2020], z[2020];
void Multiply(const bool a[2][2], bool b[2][2]) {
  bool c[2][2];
  c[0][0] = (a[0][0] & b[0][0]) ^ (a[0][1] & b[1][0]);
  c[0][1] = (a[0][0] & b[0][1]) ^ (a[0][1] & b[1][1]);
  c[1][0] = (a[1][0] & b[0][0]) ^ (a[1][1] & b[1][0]);
  c[1][1] = (a[1][0] & b[0][1]) ^ (a[1][1] & b[1][1]);
  memcpy(b, c, sizeof(bool) * 4);
  return;
}
int main(void) {
  int n, m, k, x;
  char s[4];
  int i, j, l;
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++) c[i][0][0] = c[i][1][1] = true;
  for (i = l = 0; i < m; i++) {
    scanf("%s %d", s, &k);
    while (k--) {
      scanf("%d", &x);
      x--;
      if (s[0] == 'm') {
        f[l][x << 1] = c[x][0][0];
        f[l][x << 1 | 1] = c[x][0][1];
        f[l + 1][x << 1] = c[x][1][0];
        f[l + 1][x << 1 | 1] = c[x][1][1];
      } else if (s[0] == 'R' && s[1] == 'Y')
        Multiply(d[0], c[x]);
      else if (s[0] == 'R' && s[1] == 'B')
        Multiply(d[1], c[x]);
      else
        Multiply(d[2], c[x]);
    }
    if (s[0] == 'm') {
      scanf("%s", s);
      f[l][n << 1] = s[0] == 'R' || s[0] == 'B';
      f[l + 1][n << 1] = s[0] == 'Y' || s[0] == 'B';
      l += 2;
    }
  }
  l = max(l, n << 1);
  for (i = k = 0; k < (n << 1); i++, k++) {
    for (j = i; j < l && !f[j][k]; j++)
      ;
    if (j == l) {
      z[k] = true;
      i--;
      continue;
    }
    if (i != j) swap(f[i], f[j]);
    for (j = i + 1; j < l; j++)
      if (f[j][k]) f[j] ^= f[i];
  }
  for (i = 0; i < l; i++) {
    f[i].flip(n << 1);
    if (f[i].none()) {
      printf("NO\n");
      return 0;
    }
    f[i].flip(n << 1);
  }
  for (i = l - 1, j = (n << 1) - 1; i > -1 && j > -1; i--) {
    if (z[j]) {
      j--;
      i++;
      continue;
    }
    if (f[i][j]) {
      o[j] = f[i][n << 1];
      for (k = i - 1; k > -1; k--)
        if (f[k][j]) f[k] ^= f[i];
      j--;
    }
  }
  printf("YES\n");
  for (i = 0; i < n; i++) {
    k = o[i << 1 | 1] << 1 | o[i << 1];
    printf("%c", !k ? '.' : k == 1 ? 'R' : k == 2 ? 'Y' : 'B');
  }
  printf("\n");
  return 0;
}
