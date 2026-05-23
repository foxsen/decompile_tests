#include <bits/stdc++.h>
template <typename T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) x = x * 10 + (c ^ 48), c = getchar();
}
using namespace std;
char s[59][59];
int n;
int fath[59], siz[59];
int find(int cur) {
  return fath[cur] == cur ? cur : fath[cur] = find(fath[cur]);
}
inline void merge(int u, int v) {
  u = find(u), v = find(v);
  if (u != v) fath[u] = v, siz[v] += siz[u];
}
inline void failed() {
  puts("-1");
  exit(0);
}
int blong[59], btot;
int ans;
int e[59][59], sz[8401000];
unsigned int f[8401000], yuan[8401000];
inline void FWT_OR(unsigned int *a) {
  int n = 1 << btot;
  for (int i = 1; i < n; i <<= 1) {
    for (int j = 0; j < n; j += (i << 1)) {
      for (int k = 0; k < i; ++k) {
        a[j + k + i] += a[j + k];
      }
    }
  }
}
int main() {
  read(n);
  for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1), fath[i] = i, siz[i] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (s[i][j] == 'A') {
        merge(i, j);
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (s[i][j] == 'X') {
        int u = find(i), v = find(j);
        if (u == v) failed();
      }
    }
  }
  for (int i = 1; i <= n; ++i)
    if (fath[i] == i && siz[i] == 1)
      ++ans;
    else if (fath[i] == i)
      blong[i] = btot++;
  if (!btot) {
    printf("%d\n", n - 1);
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j)
      if (s[i][j] == 'X') {
        if (siz[find(i)] == 1 || siz[find(j)] == 1) continue;
        int u = blong[find(i)], v = blong[find(j)];
        e[u][v] = e[v][u] = true;
      }
  }
  int All = (1 << btot) - 1;
  for (int s = 1; s <= All; ++s) {
    sz[s] = sz[s ^ ((s) & (-(s)))] + 1;
    if (!(s ^ ((s) & (-(s))))) {
      f[s] = true;
      continue;
    }
    int ptr = 0;
    while (!((s >> ptr) & 1)) ++ptr;
    if (!f[s ^ (1 << ptr)]) continue;
    bool flag = false;
    for (int i = ptr + 1; i < btot; ++i)
      if ((s >> i) & 1) {
        if (e[i][ptr]) {
          flag = true;
          break;
        }
      }
    if (!flag) f[s] = true;
  }
  if (f[All]) {
    printf("%d\n", n);
    return 0;
  }
  FWT_OR(f);
  memcpy(yuan, f, sizeof(f));
  int k = 1;
  while (true) {
    ++k;
    for (int i = 1; i <= All; ++i) f[i] = f[i] * yuan[i];
    unsigned int res = 0;
    for (int s = 1; s <= All; ++s) {
      if ((sz[All] - sz[s]) & 1)
        res -= f[s];
      else
        res += f[s];
    }
    if (res) {
      printf("%d\n", n + k - 1);
      return 0;
    }
  }
  return 0;
}
