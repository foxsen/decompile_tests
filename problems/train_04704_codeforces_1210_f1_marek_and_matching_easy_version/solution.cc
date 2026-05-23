#include <bits/stdc++.h>
using namespace std;
const int Mxxx = 1e5;
inline char gc() {
  static char buf[Mxxx], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, Mxxx, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline char pc(char ch, bool fl) {
  static char buf[Mxxx], *p1 = buf, *p2 = buf + Mxxx;
  return (fl || ((*p1++ = ch) && p1 == p2)) &&
             (fwrite(buf, 1, p1 - buf, stdout), p1 = buf),
         0;
}
inline int read() {
  char ch = gc();
  int gflag = 0, gans = 0;
  while (ch < '0' || ch > '9') {
    gflag |= (ch == '-');
    ch = gc();
  }
  while ('0' <= ch && ch <= '9') {
    gans = (gans << 1) + (gans << 3) + (ch ^ 48);
    ch = gc();
  }
  return gflag ? -gans : gans;
}
template <typename T>
inline char read(T &gans) {
  char ch = gc();
  int gflag = 0;
  gans = 0;
  while (ch < '0' || ch > '9') {
    gflag |= (ch == '-');
    ch = gc();
  }
  while ('0' <= ch && ch <= '9') {
    gans = (gans << 1) + (gans << 3) + (ch ^ 48);
    ch = gc();
  }
  gans = gflag ? -gans : gans;
  return ch;
}
template <typename T>
inline void write(T x) {
  if (x > 9) {
    write(x / 10);
  }
  pc(x % 10 ^ 48, false);
}
template <typename T>
inline void writenum(T x, char ch) {
  if (x < 0) {
    pc('-', false);
    x = -x;
  }
  write(x);
  pc(ch, false);
}
inline void writechar(char x, char ch) {
  pc(x, false);
  pc(ch, false);
}
template <typename T>
inline T Min(T x, T y) {
  return x < y ? x : y;
}
template <typename T>
inline T Max(T x, T y) {
  return x > y ? x : y;
}
template <typename T>
inline T Abs(T x) {
  return x > 0 ? x : -x;
}
template <typename T>
inline void ckmx(T &x, T y) {
  x = Max(x, y);
}
template <typename T>
inline void ckmn(T &x, T y) {
  x = Min(x, y);
}
const int M = 128;
const int Mod = 1e9 + 7;
inline int Ad(int x, int y = 0) { return (x += y) >= Mod ? x - Mod : x; }
inline void Add(int &x, int y) { x = Ad(x, y); }
inline void Mul(int &x, int y) { x = (((long long)(x) * (y)) % Mod); }
inline int Ksm(int x, int y) {
  int nm = 1;
  for (; y; y >>= 1) {
    if (y & 1) {
      Mul(nm, x);
    }
    Mul(x, x);
  }
  return nm;
}
inline int Inv(int x) { return Ksm(x, Mod - 2); }
const int Inv100 = Inv(100);
const int Mx = 7;
const int MX = 1 << 16;
int n, tot, p[Mx + 5][Mx + 5], prb[Mx + 5][M + 5], trs[MX + 5][M + 5],
    F[Mx + 5][MX + 5];
bitset<M> al;
unordered_map<bitset<M>, int> mp;
inline int Pre_DFS(const bitset<M> a) {
  if (mp.find(a) != mp.end()) {
    return mp[a];
  }
  int i, j, t = mp[a] = ++tot;
  bitset<M> b, pre[Mx + 5];
  for (i = 1; i <= n; i++) {
    pre[i].reset();
    for (j = (1 << n) - 1; ~j; j--) {
      if ((j >> (i - 1)) & 1 && a[j ^ (1 << (i - 1))]) {
        pre[i][j] = 1;
      }
    }
  }
  for (i = (1 << n) - 1; ~i; i--) {
    b = a;
    for (j = 1; j <= n; j++) {
      if ((i >> (j - 1)) & 1) {
        b |= pre[j];
      }
    }
    trs[t][i] = Pre_DFS(b);
  }
  return t;
}
signed main() {
  int i, j, k;
  n = read();
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      p[i][j] = (((long long)(Inv100) * (read())) % Mod);
    }
  }
  for (i = (1 << n) - 1; ~i; i--) {
    al[i] = 1;
  }
  F[0][Pre_DFS(1)] = 1;
  for (i = 1; i <= n; i++) {
    for (j = (1 << n) - 1; ~j; j--) {
      for (k = prb[i][j] = 1; k <= n; k++) {
        Mul(prb[i][j], (j >> (k - 1)) & 1 ? p[i][k] : Ad(1 - p[i][k], Mod));
      }
    }
  }
  for (i = 1; i <= n; i++) {
    for (k = 1; k <= tot; k++) {
      if (!F[i - 1][k]) {
        continue;
      }
      for (j = (1 << n) - 1; ~j; j--) {
        Add(F[i][trs[k][j]], (((long long)(F[i - 1][k]) * (prb[i][j])) % Mod));
      }
    }
  }
  writenum(F[n][mp[al]], 10);
  return pc('!', true);
}
