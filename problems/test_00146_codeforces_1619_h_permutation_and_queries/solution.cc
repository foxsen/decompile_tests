#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u32 = unsigned int;
using db = double;
using ld = long double;
using pii = std::array<int, 2>;
using pll = std::array<ll, 2>;
const int INF = 0x3f3f3f3f;
const long long INFll = 0x3f3f3f3f3f3f3f3f;
namespace Fast_in {
template <typename T>
void in(T &x) {
  x = 0;
  bool f = false;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = true;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  if (f) x = -x;
}
template <typename T>
T in() {
  T x = 0;
  bool f = false;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = true;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return f ? -x : x;
}
template <typename T, typename... Tp>
void in(T &x, Tp &...a) {
  in(x);
  in(a...);
}
template <typename T>
void in(T *l, T *r) {
  for (; l != r; ++l) in(*l);
}
}  // namespace Fast_in
using namespace Fast_in;
namespace Fast_out {
template <typename T>
void out_sub(T x, char ch = '\n') {
  static int tp, sk[30];
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  do {
    sk[++tp] = x % 10;
    x /= 10;
  } while (x);
  while (tp) {
    putchar(sk[tp--] + '0');
  }
  putchar(ch);
}
void out(int x, char ch = '\n') { out_sub(x, ch); }
void out(ll x, char ch = '\n') { out_sub(x, ch); }
void out(u32 x, char ch = '\n') { out_sub(x, ch); }
void out(ull x, char ch = '\n') { out_sub(x, ch); }
void out(db x, char ch = '\n') { printf("%.12f%c", x, ch); }
void out(ld x, char ch = '\n') { printf("%.12Lf%c", x, ch); }
void out(char x, char ch = '\n') { printf("%d%c", x, ch); }
void out(char *x, char ch = '\n') { printf("%s%c", x, ch); }
void out(string x, char ch = '\n') { printf("%s%c", x.c_str(), ch); }
void out(pii x) { out_sub(x[0], ' '), out_sub(x[1]); }
void out(pll x) { out_sub(x[0], ' '), out_sub(x[1]); }
template <typename T>
void out(vector<T> x, char ch = ' ') {
  if (x.empty()) {
    puts("");
    return;
  }
  T val = x.back();
  x.pop_back();
  for (auto i : x) out(i, ch);
  out(val);
}
template <typename T>
void out(set<T> x, char ch = ' ') {
  if (x.empty()) {
    puts("");
    return;
  }
  T val = *x.rbegin();
  x.erase(--x.end());
  for (auto i : x) out(i, ch);
  out(val);
}
template <typename T>
void out(T *l, T *r, char ch = ' ') {
  if (l == r) {
    puts("");
    return;
  }
  --r;
  for (; l != r; ++l) out(*l, ch);
  if (l == r) out(*l);
}
template <typename T, typename... Tp>
void out(T x, Tp... a) {
  out(x, ' ');
  out(a...);
}
}  // namespace Fast_out
using namespace Fast_out;
namespace Bin {
template <typename T>
void out_bin(T x, char ch = '\n') {
  long long val = 1ll << 32;
  bool flg = false;
  if (x > val) {
    for (int i = 63; ~i; --i)
      if (flg)
        printf("%d", (x >> i) & 1);
      else if ((x >> i) & 1) {
        flg = true;
        printf("1");
      }
  } else {
    for (int i = 31; ~i; --i)
      if (flg)
        printf("%d", (x >> i) & 1);
      else if ((x >> i) & 1) {
        flg = true;
        printf("1");
      }
  }
  putchar(ch);
}
template <typename T>
void in_bin(T &x) {
  x = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) {
    x <<= 1;
    x |= ch & 1;
    ch = getchar();
  }
}
}  // namespace Bin
using namespace Bin;
struct Timer {
  int val, pre;
  Timer() {
    pre = clock();
    val = clock();
  }
  void operator()(int flg = 2) {
    if (flg == 2) val = pre;
    int now = clock();
    if (flg != 0) std::cerr << now - val << "ms\n";
    if (flg != 1) val = now;
    pre = now;
  }
};
Timer Time;
template <typename T>
void Max(T &x, T y) {
  x < y && (x = y);
}
template <typename T>
void Min(T &x, T y) {
  x > y && (x = y);
}
template <typename T, class Func>
void Max(T &x, T y, Func F) {
  if (x < y) {
    x = y;
    F();
  }
}
template <typename T, class Func>
void Min(T &x, T y, Func F) {
  if (x > y) {
    x = y;
    F();
  }
}
template <typename T>
T abss(T x) {
  return x < 0 ? -x : x;
}
void File(string In, string Out) {
  if (!In.empty()) freopen(In.c_str(), "r", stdin);
  if (!Out.empty()) freopen(Out.c_str(), "w", stdout);
}
namespace Mod {
const int md = 998244353;
inline int add(const int &a, const int &b) {
  int p = a + b;
  if (p >= md) p -= md;
  return p;
}
inline int sub(const int &a, const int &b) {
  int p = a - b;
  if (p < 0) p += md;
  return p;
}
inline int __mul(const int &a, const int &b) { return 1ll * a * b % md; }
inline int mul(const int &a, const int &b) {
  int p = __mul(a, b);
  if (p < 0) p += md;
  return p;
}
template <typename T>
int qpow(int a, T b) {
  int ret = 1;
  for (; b; b >>= 1, a = mul(a, a))
    if (b & 1) ret = mul(ret, a);
  return ret;
}
inline int inv(int x) { return qpow(x, md - 2); }
inline void inv(int *F, int len, int *G = NULL, bool flg = false) {
  if (G == NULL) G = F;
  if (flg) {
    F[0] = G[0] = 1;
    for (int i = 1; i <= len; ++i) F[i] = __mul(F[i - 1], i);
  }
  std::vector<int> S(len + 1), iS(len + 1);
  S[0] = 1;
  for (int i = 1; i <= len; ++i) S[i] = mul(S[i - 1], F[i]);
  iS[len] = inv(S[len]);
  for (int i = len; i >= 1; --i) {
    iS[i - 1] = mul(iS[i], F[i]);
    G[i] = mul(S[i - 1], iS[i]);
  }
}
}  // namespace Mod
using namespace Mod;
namespace gvihvo {
const int N = 100010;
struct FHQ_Treap {
  int fa, son[2];
  int val, siz, key;
};
int cnt;
int c, rt[N], irt[N];
FHQ_Treap t[N];
int new_node(int v) {
  t[++cnt].val = v;
  t[cnt].siz = 1;
  t[cnt].key = rand();
  return cnt;
}
void pushup(int x) {
  t[x].siz = t[t[x].son[0]].siz + t[t[x].son[1]].siz + 1;
  if (t[x].son[0]) t[t[x].son[0]].fa = x;
  if (t[x].son[1]) t[t[x].son[1]].fa = x;
  t[x].fa = 0;
}
pii split(int x, int k) {
  if (!x) return {0, 0};
  if (t[t[x].son[0]].siz >= k) {
    pii ret = split(t[x].son[0], k);
    t[x].son[0] = ret[1];
    pushup(x);
    return {ret[0], x};
  } else {
    pii ret = split(t[x].son[1], k - t[t[x].son[0]].siz - 1);
    t[x].son[1] = ret[0];
    pushup(x);
    return {x, ret[1]};
  }
}
int Merge(int x, int y) {
  if (!x || !y) return x | y;
  if (t[x].key > t[y].key) {
    t[x].son[1] = Merge(t[x].son[1], y);
    pushup(x);
    return x;
  } else {
    t[y].son[0] = Merge(x, t[y].son[0]);
    pushup(y);
    return y;
  }
}
void Insert(int x, int v) {
  rt[x] = Merge(rt[x], new_node(v));
  irt[rt[x]] = x;
}
int kth(int x, int k) {
  pii tmp1 = split(x, k - 1);
  pii tmp2 = split(tmp1[1], 1);
  int ret = t[tmp2[0]].val;
  Merge(tmp1[0], Merge(tmp2[0], tmp2[1]));
  return ret;
}
int Find_Root(int x) {
  while (t[x].fa) x = t[x].fa;
  return x;
}
int rank(int x) {
  int ret = t[t[x].son[0]].siz + 1;
  while (t[x].fa) {
    int y = t[x].fa;
    if (x == t[y].son[1]) ret += t[t[y].son[0]].siz + 1;
    x = y;
  }
  return ret;
}
void print(int x) {
  if (t[x].son[0]) print(t[x].son[0]);
  out(t[x].val);
  if (t[x].son[1]) print(t[x].son[1]);
}
int n, q;
int p[N];
bool vis[N];
int pos[N];
void main() {
  in(n, q);
  in(p + 1, p + n + 1);
  for (int i = (1); i <= (n); ++i) {
    if (vis[p[i]]) continue;
    int x = p[i], now = p[p[i]];
    vis[x] = true;
    rt[++c] = new_node(x);
    irt[rt[c]] = c;
    pos[x] = cnt;
    while (now != x) {
      Insert(c, now);
      pos[now] = cnt;
      vis[now] = true;
      now = p[now];
    }
  }
  for (int i = (1); i <= (q); ++i) {
    int op, x, y;
    in(op, x, y);
    if (op == 1) {
      int rx = Find_Root(pos[p[x]]), ry = Find_Root(pos[p[y]]);
      if (rx == ry) {
        int kx = rank(pos[p[x]]), ky = rank(pos[p[y]]);
        if (kx > ky) {
          swap(x, y);
          swap(kx, ky);
        }
        pii tmp = split(rx, kx);
        pii tmp2 = split(tmp[1], ky - kx);
        int r = irt[rx];
        rt[r] = Merge(tmp[0], tmp2[1]);
        irt[rt[r]] = r;
        rt[++c] = tmp2[0];
        irt[rt[c]] = c;
      } else {
        int kx = rank(pos[p[x]]), ky = rank(pos[p[y]]);
        pii tmp1 = split(rx, kx);
        pii tmp2 = split(ry, ky);
        int r = irt[rx];
        rt[r] = Merge(Merge(tmp1[0], tmp2[1]), Merge(tmp2[0], tmp1[1]));
        irt[rt[r]] = r;
      }
      swap(pos[p[x]], pos[p[y]]);
      swap(t[pos[p[x]]].val, t[pos[p[y]]].val);
      swap(p[x], p[y]);
    } else {
      int tmp = Find_Root(pos[x]);
      y += rank(pos[x]);
      y %= t[tmp].siz;
      if (!y) y += t[tmp].siz;
      out(kth(tmp, y));
    }
  }
}
void init() { ; }
}  // namespace gvihvo
int main() {
  gvihvo::init();
  gvihvo::main();
  return 0;
}
