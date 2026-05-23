#include <bits/stdc++.h>
using namespace std;
const double pi = acos(0.0) * 2.0;
const long double eps = 1e-10;
const int step[8][2] = {{-1, 0}, {0, 1}, {1, 0},  {0, -1},
                        {-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
template <class T>
inline T abs1(T a) {
  return a < 0 ? -a : a;
}
template <typename t, typename t1>
t min1(t a, t1 b) {
  return a < b ? a : b;
}
template <typename t, typename... arg>
t min1(t a, arg... arr) {
  return min1(a, min1(arr...));
}
template <typename t, typename t1>
t max1(t a, t1 b) {
  return a > b ? a : b;
}
template <typename t, typename... arg>
t max1(t a, arg... arr) {
  return max1(a, max1(arr...));
}
inline int jud(double a, double b) {
  if (abs(a) < eps && abs(b) < eps)
    return 0;
  else if (abs1(a - b) / max(abs1(a), abs1(b)) < eps)
    return 0;
  if (a < b) return -1;
  return 1;
}
template <typename t>
inline int jud(t a, t b) {
  if (a < b) return -1;
  if (a == b) return 0;
  return 1;
}
template <typename it, typename t1>
inline int find(t1 val, it a, int na, bool f_small = 1, bool f_lb = 1) {
  if (na == 0) return 0;
  int be = 0, en = na - 1;
  if (*a <= *(a + na - 1)) {
    if (f_lb == 0)
      while (be < en) {
        int mid = (be + en + 1) / 2;
        if (jud(*(a + mid), val) != 1)
          be = mid;
        else
          en = mid - 1;
      }
    else
      while (be < en) {
        int mid = (be + en) / 2;
        if (jud(*(a + mid), val) != -1)
          en = mid;
        else
          be = mid + 1;
      }
    if (f_small && jud(*(a + be), val) == 1) be--;
    if (!f_small && jud(*(a + be), val) == -1) be++;
  } else {
    if (f_lb)
      while (be < en) {
        int mid = (be + en + 1) / 2;
        if (jud(*(a + mid), val) != -1)
          be = mid;
        else
          en = mid - 1;
      }
    else
      while (be < en) {
        int mid = (be + en) / 2;
        if (jud(*(a + mid), val) != 1)
          en = mid;
        else
          be = mid + 1;
      }
    if (!f_small && jud(*(a + be), val) == -1) be--;
    if (f_small && jud(*(a + be), val) == 1) be++;
  }
  return be;
}
template <class T>
inline T lowb(T num) {
  return num & (-num);
}
inline int bitnum(unsigned int nValue) { return __builtin_popcount(nValue); }
inline int bitnum(int nValue) { return __builtin_popcount(nValue); }
inline int bitnum(unsigned long long nValue) {
  return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32);
}
inline int bitnum(long long nValue) {
  return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32);
}
inline int bitmaxl(unsigned int a) {
  if (a == 0) return 0;
  return 32 - __builtin_clz(a);
}
inline int bitmaxl(int a) {
  if (a == 0) return 0;
  return 32 - __builtin_clz(a);
}
inline int bitmaxl(unsigned long long a) {
  int temp = a >> 32;
  if (temp) return 32 - __builtin_clz(temp) + 32;
  return bitmaxl(int(a));
}
inline int bitmaxl(long long a) {
  int temp = a >> 32;
  if (temp) return 32 - __builtin_clz(temp) + 32;
  return bitmaxl(int(a));
}
long long pow(long long n, long long m, long long mod = 0) {
  if (m < 0) return 0;
  long long ans = 1;
  long long k = n;
  while (m) {
    if (m & 1) {
      ans *= k;
      if (mod) ans %= mod;
    }
    k *= k;
    if (mod) k %= mod;
    m >>= 1;
  }
  return ans;
}
template <class t1, class t2>
inline void add(t1 &a, t2 b, int mod = -1) {
  if (mod == -1) mod = 1000000007;
  a += b;
  while (a >= mod) a -= mod;
  while (a < 0) a += mod;
}
template <class t>
void output1(t arr) {
  for (int i = 0; i < (int)arr.size(); i++) cerr << arr[i] << ' ';
  cerr << endl;
}
template <class t>
void output2(t arr) {
  for (int i = 0; i < (int)arr.size(); i++) output1(arr[i]);
}
const int maxn = 500100;
struct edge {
  int to, nxt, ch;
} e[maxn * 2];
int head[maxn], le;
int fa[maxn];
int deep[maxn], sz[maxn], bs[maxn], val[maxn];
int n;
int ans[maxn];
int table[1 << 22];
int tans;
void addedge(int a, int b, int ch) {
  e[le].to = b;
  e[le].nxt = head[a];
  e[le].ch = ch;
  head[a] = le++;
}
void del(int no) {
  table[val[no]] = -n;
  for (int i = head[no]; i != -1; i = e[i].nxt) del(e[i].to);
}
void getans(int no, int op) {
  tans = max(table[val[no]] + deep[no] - op * 2, tans);
  for (int i = 0; i < 22; i++) {
    tans = max(tans, table[val[no] ^ (1 << i)] + deep[no] - op * 2);
  }
  for (int i = head[no]; i != -1; i = e[i].nxt) getans(e[i].to, op);
}
void upd(int no) {
  table[val[no]] = max(table[val[no]], deep[no]);
  for (int i = head[no]; i != -1; i = e[i].nxt) upd(e[i].to);
}
void dfssz(int no) {
  sz[no] = 1;
  for (int i = head[no]; i != -1; i = e[i].nxt) {
    deep[e[i].to] = deep[no] + 1;
    val[e[i].to] = 1 << e[i].ch;
    val[e[i].to] ^= val[no];
    dfssz(e[i].to);
    sz[no] += sz[e[i].to];
    if (bs[no] == 0 || sz[e[i].to] > sz[bs[no]]) bs[no] = e[i].to;
  }
}
void dfs(int no) {
  for (int i = head[no]; i != -1; i = e[i].nxt)
    if (e[i].to != bs[no]) {
      dfs(e[i].to);
    }
  if (bs[no] != 0) dfs(bs[no]);
  table[val[no]] = max(table[val[no]], deep[no]);
  tans = max(0, table[val[no]] - deep[no]);
  for (int i = 0; i < 22; i++)
    tans = max(tans, table[val[no] ^ (1 << i)] - deep[no]);
  for (int i = head[no]; i != -1; i = e[i].nxt)
    if (e[i].to != bs[no]) {
      getans(e[i].to, deep[no]);
      upd(e[i].to);
    }
  ans[no] = tans;
  if (fa[no] != -1 && bs[fa[no]] != no) {
    table[val[no]] = -n;
    for (int i = head[no]; i != -1; i = e[i].nxt) del(e[i].to);
  }
  for (int i = head[no]; i != -1; i = e[i].nxt)
    ans[no] = max(ans[no], ans[e[i].to]);
}
int main() {
  ios_base::sync_with_stdio(0);
  memset(head, -1, sizeof(head));
  fa[0] = -1;
  scanf("%d", &n);
  for (int i = 0; i < 1 << 22; i++) table[i] = -n;
  for (int i = 1; i < n; i++) {
    int no;
    char str[3];
    scanf("%d%s", &no, str);
    no--;
    fa[i] = no;
    addedge(no, i, str[0] - 'a');
  }
  dfssz(0);
  dfs(0);
  for (int i = 0; i < n; i++) printf("%d\n", ans[i]);
  return 0;
}
