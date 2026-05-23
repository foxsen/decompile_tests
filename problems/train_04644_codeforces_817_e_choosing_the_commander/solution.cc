#include <bits/stdc++.h>
using namespace std;
namespace FASTIN {
static char buf[1 << 20], *p1, *p2;
inline char getc() {
  if (p1 == p2) {
    p1 = buf;
    p2 = buf + fread(buf, 1, 1 << 20, stdin);
    if (p1 == p2) return EOF;
  }
  return *p1++;
}
inline int readint() {
  register int f = 0, sign = 1;
  register char ch = getc();
  while (ch < '0' || ch > '9') {
    if (ch == '-') sign = -1;
    ch = getc();
  }
  while (ch >= '0' && ch <= '9') {
    f = (f << 1) + (f << 3) + (ch ^ 48);
    ch = getc();
  }
  return f * sign;
}
inline long long readLL() {
  register long long f = 0, sign = 1;
  register char ch = getc();
  while (ch < '0' || ch > '9') {
    if (ch == '-') sign = -1;
    ch = getc();
  }
  while (ch >= '0' && ch <= '9') {
    f = (f << 1) + (f << 3) + (ch ^ 48);
    ch = getc();
  }
  return f * sign;
}
}  // namespace FASTIN
using namespace FASTIN;
int Q, opt, p, l;
namespace Trie {
const int N = 5e5 + 5;
const int MAXBIT = 31;
int tot = 1, Tree[N * MAXBIT][2] = {0}, SIZE[N * MAXBIT * 2] = {0};
void Insert(int x) {
  int now = 1, key;
  for (int i = MAXBIT; ~i; --i) {
    key = x >> i & 1;
    if (Tree[now][key] == 0) Tree[now][key] = ++tot;
    now = Tree[now][key];
    SIZE[now]++;
  }
  return;
}
void Delete(int x) {
  int now = 1, key;
  for (int i = MAXBIT; ~i; --i) {
    key = x >> i & 1;
    if (Tree[now][key] == 0) return;
    now = Tree[now][key];
    SIZE[now]--;
  }
  return;
}
int Query(int p, int l) {
  int now = 1, key, bit, res = 0;
  for (int i = MAXBIT; ~i; --i) {
    key = p >> i & 1, bit = l >> i & 1;
    if (bit == 0) {
      now = Tree[now][key];
    } else {
      res += SIZE[Tree[now][key]], now = Tree[now][key ^ 1];
    }
  }
  return res;
}
}  // namespace Trie
using namespace Trie;
int main() {
  Q = readint();
  while (Q--) {
    opt = readint();
    if (opt == 1) {
      p = readint();
      Insert(p);
    } else if (opt == 2) {
      p = readint();
      Delete(p);
    } else {
      p = readint(), l = readint();
      printf("%d\n", Query(p, l));
    }
  }
  return 0;
}
