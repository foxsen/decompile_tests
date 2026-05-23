#include <bits/stdc++.h>
using namespace std;
char gc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  return x * f;
}
inline long long readll() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  return x * f;
}
inline void write(int x) {
  if (!x) putchar('0');
  if (x < 0) x = -x, putchar('-');
  static int sta[20];
  register int tot = 0;
  while (x) sta[tot++] = x % 10, x /= 10;
  while (tot) putchar(sta[--tot] + 48);
}
const int maxn = 1007, INF = 0x3f3f3f3f;
const int MOD = 998244353;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const long long P = 19260817;
inline int mod1(int x) { return x < MOD ? x : x - MOD; }
inline int mod2(int x) { return x < 0 ? x + MOD : x; }
inline void add(int &x, int y) { x = mod1(x + y); }
inline void sub(int &x, int y) { x = mod2(x - y); }
int n, m, k;
int u[maxn], v[maxn];
map<string, int> name;
struct UFS {
  int fa[maxn];
  bitset<1007> key[1007];
  bitset<1007> p[1007];
  int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
  void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x > y) swap(x, y);
    if (x == y) return;
    fa[y] = x;
    key[x] |= key[y];
    p[x] |= p[y];
  }
  void init() {
    for (int i = 1; i <= n; i++) fa[i] = i;
  }
} U1, U2;
string s;
int vis[maxn];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", u + i, v + i);
  }
  U1.init();
  for (int i = 1; i <= k; i++) {
    cin >> s;
    name[s] = i;
    int pos, num;
    scanf("%d", &pos);
    U1.p[pos].set(name[s]);
    scanf("%d", &num);
    for (int j = 1; j <= num; j++) {
      int x;
      scanf("%d", &x);
      U1.key[pos].set(x);
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      if (!vis[j] &&
          (U1.key[U1.find(u[j])][j] == 1 || U1.key[U1.find(v[j])][j] == 1)) {
        U1.merge(u[j], v[j]);
        vis[j] = 1;
      }
    }
  }
  U2.init();
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= k; i++) {
    cin >> s;
    int pos, num;
    scanf("%d", &pos);
    U2.p[pos].set(name[s]);
    scanf("%d", &num);
    for (int j = 1; j <= num; j++) {
      int x;
      scanf("%d", &x);
      U2.key[pos].set(x);
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      if (!vis[j] &&
          (U2.key[U2.find(u[j])][j] == 1 || U2.key[U2.find(v[j])][j] == 1)) {
        U2.merge(u[j], v[j]);
        vis[j] = 1;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (U1.find(i) == i) {
      if (U2.find(i) != i) {
        printf("NO");
        return 0;
      }
      if (U1.key[i] != U2.key[i]) {
        printf("NO");
        return 0;
      }
      if (U1.p[i] != U2.p[i]) {
        printf("NO");
        return 0;
      }
    }
  }
  printf("YES");
  return 0;
}
