#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline int read() {
  char c = getchar();
  int tot = 1;
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') {
    tot = -1;
    c = getchar();
  }
  int sum = 0;
  while (c >= '0' && c <= '9') {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  return sum * tot;
}
inline void wr(long long x) {
  if (x < 0) {
    putchar('-');
    wr(-x);
    return;
  }
  if (x >= 10) wr(x / 10);
  putchar(x % 10 + '0');
}
inline void wrn(long long x) {
  wr(x);
  putchar('\n');
}
inline void wri(int x) {
  wr(x);
  putchar(' ');
}
inline void wrn(int x, int y) {
  wri(x);
  wrn(y);
}
inline void wrn(int a, int b, int c) {
  wri(a);
  wrn(b, c);
}
int n, m, K;
long long ans;
int s[3055][3055], up[8], down[8];
inline int sum(int x1, int x2, int y1, int y2) {
  return s[x2][y2] - s[x2][y1] - s[x1][y2] + s[x1][y1];
}
void work(int x1, int x2, int y1, int y2, bool dir) {
  if (x1 == x2 || y1 == y2) return;
  if ((x1 + 1 == x2) && (y1 + 1 == y2)) {
    ans += sum(x1, x2, y1, y2) == K;
    return;
  }
  if (dir) {
    int mid = ((x1 + x2) >> 1);
    work(x1, mid, y1, y2, !dir);
    work(mid, x2, y1, y2, !dir);
    for (int i = y1; i < y2; i++) {
      up[0] = down[0] = mid;
      for (int k = 1; k <= K + 1; k++) up[k] = x1, down[k] = x2;
      for (int j = i + 1; j <= y2; j++) {
        for (int k = 1; k <= K + 1; k++)
          while (sum(up[k], mid, i, j) >= k) up[k]++;
        for (int k = 1; k <= K + 1; k++)
          while (sum(mid, down[k], i, j) >= k) down[k]--;
        for (int k = 0; k <= K; k++)
          ans += (up[k] - up[k + 1]) * (down[K - k + 1] - down[K - k]);
      }
    }
  } else {
    int mid = ((y1 + y2) >> 1);
    work(x1, x2, y1, mid, !dir);
    work(x1, x2, mid, y2, !dir);
    for (int i = x1; i < x2; i++) {
      up[0] = down[0] = mid;
      for (int k = 1; k <= K + 1; k++) up[k] = y1, down[k] = y2;
      for (int j = i + 1; j <= x2; j++) {
        for (int k = 1; k <= K + 1; k++)
          while (sum(i, j, up[k], mid) >= k) up[k]++;
        for (int k = 1; k <= K + 1; k++)
          while (sum(i, j, mid, down[k]) >= k) down[k]--;
        for (int k = 0; k <= K; k++)
          ans += (up[k] - up[k + 1]) * (down[K - k + 1] - down[K - k]);
      }
    }
  }
}
char str[3055];
int main() {
  n = read();
  m = read();
  K = read();
  for (int i = (1); i <= (n); i++) {
    scanf("%s", str + 1);
    for (int j = (1); j <= (m); j++)
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + str[j] - '0';
  }
  work(0, n, 0, m, 0);
  wrn(ans);
  return 0;
}
