#include <bits/stdc++.h>
using namespace std;
template <class T>
bool chkmin(T& a, T b) {
  return a > b ? a = b, true : false;
}
template <class T>
bool chkmax(T& a, T b) {
  return a < b ? a = b, true : false;
}
template <class T>
void read(T& a) {
  char c = getchar_unlocked();
  T f = 1;
  a = 0;
  for (; !isdigit(c); c = getchar_unlocked())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar_unlocked()) a = a * 10 + c - '0';
  a *= f;
}
const int maxN = 1e6 + 6, mo = 1e9 + 7;
int fail[maxN];
int N, M, tot;
int pos[maxN];
int border[maxN];
char s[maxN];
int pow_mod(int x, int t) {
  int ret = 1;
  while (t) {
    if (t & 1) ret = (long long)ret * x % mo;
    x = (long long)x * x % mo;
    t >>= 1;
  }
  return ret;
}
int main() {
  int len;
  read(N);
  read(M);
  if (M == 0) {
    printf("%d\n", pow_mod(26, N));
    return 0;
  }
  scanf("%s", s + 1);
  for (int i = (1), _ = (M); i <= _; ++i) read(pos[i]);
  fail[0] = fail[1] = 0;
  int idx = 0;
  for (int i = (2), _ = (len = strlen(s + 1)); i <= _; ++i) {
    while (idx && s[idx + 1] != s[i]) idx = fail[idx];
    if (s[idx + 1] == s[i]) ++idx;
    fail[i] = idx;
  }
  for (int c = fail[len]; c; border[++tot] = c, c = fail[c]) {
  }
  sort(border + 1, border + tot + 1);
  int ans = 1;
  if (N - pos[M] + 1 < len) {
    puts("0");
    return 0;
  } else
    ans = (long long)ans * pow_mod(26, N - pos[M] + 1 - len) % mo;
  for (int i = (M - 1), _ = (1); i >= _; --i) {
    int delta = pos[i + 1] - pos[i];
    if (delta < len) {
      int tp = lower_bound(border + 1, border + tot + 1, len - delta) - border;
      if (border[tp] != len - delta) {
        puts("0");
        return 0;
      }
    } else {
      ans = (long long)ans * pow_mod(26, delta - len) % mo;
    }
  }
  cout << (long long)ans * pow_mod(26, pos[1] - 1) % mo << endl;
  return 0;
}
