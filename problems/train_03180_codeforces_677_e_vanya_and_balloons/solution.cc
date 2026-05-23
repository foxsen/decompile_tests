#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
char maze[1010][1010];
int no[1010][1010];
int s[1010][1010];
int w[1010][1010];
int e[1010][1010];
int a[1010][1010];
int b[1010][1010];
int c[1010][1010];
int d[1010][1010];
double mul1[1010][1010];
double mul2[1010][1010];
double mul3[1010][1010];
double mul4[1010][1010];
void outint(int tmp[1010][1010], int n) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) printf("%d ", tmp[i][j]);
    printf("\n");
  }
  printf("\n");
}
void outdouble(double tmp[1010][1010], int n) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) printf("%.6lf ", tmp[i][j]);
    printf("\n");
  }
  printf("\n");
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf(" %c", &maze[i][j]);
      maze[i][j] -= '0';
    }
  }
  for (int i = 1; i <= n; i++) {
    if (maze[1][i] == 0)
      mul1[1][i] = mul3[1][i] = mul4[1][i] = 0;
    else
      mul1[1][i] = mul3[1][i] = mul4[1][i] = log(maze[1][i]);
    if (maze[i][1] == 0)
      mul2[i][1] = mul3[i][1] = 0;
    else
      mul2[i][1] = mul3[i][1] = log(maze[i][1]);
    if (maze[i][n] == 0)
      mul4[i][n] = 0;
    else
      mul4[i][n] = log(maze[i][n]);
  }
  for (int i = 2; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (maze[i][j] == 0)
        mul1[i][j] = 0;
      else
        mul1[i][j] = mul1[i - 1][j] + log(maze[i][j]);
  for (int i = 1; i <= n; i++)
    for (int j = 2; j <= n; j++)
      if (maze[i][j] == 0)
        mul2[i][j] = 0;
      else
        mul2[i][j] = mul2[i][j - 1] + log(maze[i][j]);
  for (int i = 2; i <= n; i++)
    for (int j = 2; j <= n; j++)
      if (maze[i][j] == 0)
        mul3[i][j] = 0;
      else
        mul3[i][j] = mul3[i - 1][j - 1] + log(maze[i][j]);
  for (int i = 2; i <= n; i++)
    for (int j = n - 1; j >= 1; j--)
      if (maze[i][j] == 0)
        mul4[i][j] = 0;
      else
        mul4[i][j] = mul4[i - 1][j + 1] + log(maze[i][j]);
  for (int i = 1; i <= n; i++) {
    no[1][i] = (maze[1][i] != 0);
    s[n][i] = (maze[n][i] != 0);
    w[i][1] = (maze[i][1] != 0);
    e[i][n] = (maze[i][n] != 0);
    a[1][i] = b[1][i] = (maze[1][i] != 0);
    c[n][i] = d[n][i] = (maze[n][i] != 0);
    a[i][1] = c[i][1] = (maze[i][1] != 0);
    b[i][n] = d[i][n] = (maze[i][n] != 0);
  }
  for (int i = 2; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (maze[i][j] == 0)
        no[i][j] = 0;
      else
        no[i][j] = no[i - 1][j] + 1;
  for (int i = n - 1; i >= 1; i--)
    for (int j = 1; j <= n; j++)
      if (maze[i][j] == 0)
        s[i][j] = 0;
      else
        s[i][j] = s[i + 1][j] + 1;
  for (int i = 1; i <= n; i++)
    for (int j = 2; j <= n; j++)
      if (maze[i][j] == 0)
        w[i][j] = 0;
      else
        w[i][j] = w[i][j - 1] + 1;
  for (int i = 1; i <= n; i++)
    for (int j = n - 1; j >= 1; j--)
      if (maze[i][j] == 0)
        e[i][j] = 0;
      else
        e[i][j] = e[i][j + 1] + 1;
  for (int i = 2; i <= n; i++)
    for (int j = 2; j <= n; j++)
      if (maze[i][j] == 0)
        a[i][j] = 0;
      else
        a[i][j] = a[i - 1][j - 1] + 1;
  for (int i = 2; i <= n; i++)
    for (int j = n - 1; j >= 1; j--)
      if (maze[i][j] == 0)
        b[i][j] = 0;
      else
        b[i][j] = b[i - 1][j + 1] + 1;
  for (int i = n - 1; i >= 1; i--)
    for (int j = 2; j <= n; j++)
      if (maze[i][j] == 0)
        c[i][j] = 0;
      else
        c[i][j] = c[i + 1][j - 1] + 1;
  for (int i = n - 1; i >= 1; i--)
    for (int j = n - 1; j >= 1; j--)
      if (maze[i][j] == 0)
        d[i][j] = 0;
      else
        d[i][j] = d[i + 1][j + 1] + 1;
  double maxans = -1.0;
  int posx = 1, posy = 1, dir = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int dd = min(min(no[i][j], s[i][j]), min(w[i][j], e[i][j]));
      if (dd == 0) continue;
      double tmpans = mul1[i + dd - 1][j] - mul1[i - dd][j] +
                      mul2[i][j + dd - 1] - mul2[i][j - dd] - log(maze[i][j]);
      if (tmpans > maxans) {
        maxans = tmpans;
        posx = i;
        posy = j;
        dir = 0;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int dd = min(min(a[i][j], b[i][j]), min(c[i][j], d[i][j]));
      if (dd == 0) continue;
      double tmpans = mul3[i + dd - 1][j + dd - 1] - mul3[i - dd][j - dd] +
                      mul4[i + dd - 1][j - dd + 1] - mul4[i - dd][j + dd] -
                      log(maze[i][j]);
      if (tmpans > maxans) {
        maxans = tmpans;
        posx = i;
        posy = j;
        dir = 1;
      }
    }
  }
  long long ans = 1;
  if (dir == 0) {
    int dd = min(min(no[posx][posy], s[posx][posy]),
                 min(w[posx][posy], e[posx][posy]));
    for (int i = 1; i <= dd - 1; i++) {
      ans = (ans * maze[posx + i][posy]) % mod;
      ans = (ans * maze[posx - i][posy]) % mod;
      ans = (ans * maze[posx][posy + i]) % mod;
      ans = (ans * maze[posx][posy - i]) % mod;
    }
    ans = (ans * maze[posx][posy]) % mod;
  } else {
    int dd = min(min(a[posx][posy], b[posx][posy]),
                 min(c[posx][posy], d[posx][posy]));
    for (int i = 1; i <= dd - 1; i++) {
      ans = (ans * maze[posx - i][posy - i]) % mod;
      ans = (ans * maze[posx - i][posy + i]) % mod;
      ans = (ans * maze[posx + i][posy - i]) % mod;
      ans = (ans * maze[posx + i][posy + i]) % mod;
    }
    ans = (ans * maze[posx][posy]) % mod;
  }
  printf("%I64d\n", ans);
  return 0;
}
