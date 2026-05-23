#include <bits/stdc++.h>
using namespace std;
const int N = 6010, M = N * 20, INF = 1e9;
int n, a[N], h[N], tot, e[M], nxt[M], fl[M], co[M], f[N], vis[N], calc, now[N],
    D[N], ans, In[N], Out[N], T;
bool bz[N];
void Add(int x, int y, int f, int c) {
  e[++tot] = y;
  nxt[tot] = h[x];
  fl[tot] = f;
  co[tot] = c;
  h[x] = tot;
}
bool aug(int x) {
  vis[x] = calc;
  if (x == T) return 1;
  for (int i = now[x]; i; i = nxt[i])
    if (fl[i] > 0 && f[x] == co[i ^ 1] + f[e[i]] && vis[e[i]] < calc) {
      if (aug(e[i])) {
        fl[i]--;
        fl[i ^ 1]++;
        now[x] = i;
        return 1;
      }
    }
  return now[x] = 0;
}
int main() {
  scanf("%d", &n);
  T = tot = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    In[i] = ++T;
    Out[i] = ++T;
  }
  T++;
  Add(0, 1, 4, 0);
  Add(1, 0, 0, 0);
  for (int i = 1; i <= n; i++) {
    Add(1, In[i], 1, 0);
    Add(In[i], 1, 0, 0);
    Add(In[i], Out[i], INF, 0);
    Add(Out[i], In[i], 0, 0);
    Add(In[i], Out[i], 1, -1);
    Add(Out[i], In[i], 0, 1);
    Add(Out[i], T, 1, 0);
    Add(T, Out[i], 0, 0);
    for (int j = i + 1; j <= n; j++)
      if (a[i] == a[j] + 1) {
        Add(Out[i], In[j], INF, 0);
        Add(In[j], Out[i], 0, 0);
        break;
      }
    for (int j = i + 1; j <= n; j++)
      if (a[i] == a[j] - 1) {
        Add(Out[i], In[j], INF, 0);
        Add(In[j], Out[i], 0, 0);
        break;
      }
    for (int j = i + 1; j <= n; j++)
      if (a[i] % 7 == a[j] % 7) {
        Add(Out[i], In[j], INF, 0);
        Add(In[j], Out[i], 0, 0);
        break;
      }
  }
  for (;;) {
    D[tot = 1] = T;
    memset(bz, 0, sizeof(bz));
    for (int i = 0; i < T; i++) f[i] = -INF;
    f[T] = 0;
    for (int i = 0, j, x; i != tot;) {
      i = (i + 1) % N;
      x = D[i];
      bz[x] = 0;
      for (j = h[x]; j; j = nxt[j])
        if (fl[j ^ 1] > 0 && f[x] + co[j] > f[e[j]]) {
          f[e[j]] = f[x] + co[j];
          if (!bz[e[j]]) {
            bz[e[j]] = 1;
            tot = (tot + 1) % N;
            D[tot] = e[j];
          }
        }
    }
    if (f[0] <= 0) break;
    for (memcpy(now, h, sizeof(h));;) {
      calc++;
      if (!aug(0)) break;
      ans += f[0];
    }
  }
  printf("%d\n", ans);
  return 0;
}
