#include <bits/stdc++.h>
using namespace std;
int read() {
  int xx = 0, ff = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') ff = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    xx = xx * 10 + ch - '0';
    ch = getchar();
  }
  return xx * ff;
}
long long READ() {
  long long xx = 0, ff = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') ff = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    xx = xx * 10 + ch - '0';
    ch = getchar();
  }
  return xx * ff;
}
char one() {
  char ch = getchar();
  while (ch == ' ' || ch == '\n') ch = getchar();
  return ch;
}
const int maxn = 100010;
int N, K;
int a[maxn], first[maxn], last[maxn];
int main() {
  N = read(), K = read();
  for (int i = 1; i <= K; i++) {
    a[i] = read();
    if (!first[a[i]]) first[a[i]] = i;
    last[a[i]] = i;
  }
  int ans = 0;
  for (int i = 1; i <= N; i++)
    if (!first[i]) ans++;
  for (int i = 1; i < N; i++)
    if (first[i] > last[i + 1] || !first[i] || !last[i + 1]) ans++;
  for (int i = N; i > 1; i--)
    if (first[i] > last[i - 1] || !first[i] || !last[i - 1]) ans++;
  printf("%d\n", ans);
  return 0;
}
