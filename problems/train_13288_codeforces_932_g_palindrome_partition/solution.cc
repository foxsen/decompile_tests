#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int n;
char s[1000010], t[1000010];
struct PAM {
  struct node {
    int Next[26];
    int fail;
    int len;
    int diff, anc;
    long long f;
    node(int _len = 0) {
      memset(Next, 0, sizeof Next);
      fail = 0;
      diff = anc = 0;
      f = 0;
      len = _len;
    }
  } t[1000010];
  int s[1000010];
  int last;
  int n;
  int p;
  int newnode(int len) {
    t[p] = node(len);
    return p++;
  }
  void init() {
    p = 0;
    newnode(0);
    newnode(-1);
    last = 0;
    n = 0;
    s[n] = -1;
    t[0].fail = t[1].fail = 1;
    t[0].anc = 1;
  }
  int get_fail(int x) {
    while (s[n - t[x].len - 1] != s[n]) x = t[x].fail;
    return x;
  }
  void add(int c) {
    c -= 'a';
    s[++n] = c;
    int cur = get_fail(last);
    if (!t[cur].Next[c]) {
      int now = newnode(t[cur].len + 2);
      t[now].fail = t[get_fail(t[cur].fail)].Next[c];
      t[cur].Next[c] = now;
      t[now].diff = t[now].len - t[t[now].fail].len;
      t[now].anc = (t[now].diff == t[t[now].fail].diff ? t[t[now].fail].anc
                                                       : t[now].fail);
    }
    last = t[cur].Next[c];
  }
  void gao(char *s, long long g[]) {
    init();
    g[0] = 1;
    int len = strlen(s + 1);
    for (int i = 1; i <= len; ++i) {
      add(s[i]);
      int it = last;
      while (it) {
        t[it].f = g[i - t[t[it].anc].len - t[it].diff];
        if (t[it].fail != t[it].anc) {
          (t[it].f += t[t[it].fail].f) %= mod;
        }
        if (i % 2 == 0) (g[i] += t[it].f) %= mod;
        it = t[it].anc;
      }
    }
    printf("%lld\n", g[len]);
  }
} pam;
long long g[1000010];
void run() {
  int len = strlen(s + 1);
  for (int i = 1; i <= len; i += 2) {
    t[i] = s[(i + 1) / 2];
  }
  reverse(s + 1, s + 1 + len);
  for (int i = 2; i <= len; i += 2) {
    t[i] = s[(i + 1) / 2];
  }
  memset(g, 0, sizeof g);
  pam.gao(t, g);
}
int main() {
  while (scanf("%s", s + 1) != EOF) run();
  return 0;
}
