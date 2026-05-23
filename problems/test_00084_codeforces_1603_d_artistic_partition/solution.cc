#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
using ll = long long;
template <class T>
void read(T &x) {
  char ch;
  x = 0;
  int f = 1;
  while (isspace(ch = getchar_unlocked()))
    ;
  if (ch == '-') ch = getchar_unlocked(), f = -1;
  do x = x * 10 + (ch - '0');
  while (isdigit(ch = getchar_unlocked()));
  x *= f;
}
template <class T, class... A>
void read(T &x, A &...args) {
  read(x);
  read(args...);
}
const int B = 18;
const int N = 100005;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int phi[N], p[N], pc = 0;
bool np[N];
void sieve(int n) {
  phi[1] = 1;
  for (int i = 2; i <= n; ++i) {
    if (!np[i]) p[++pc] = i, phi[i] = i - 1;
    for (int j = 1; j <= pc && i * p[j] <= n; ++j) {
      np[i * p[j]] = true;
      if (i % p[j] == 0) {
        phi[i * p[j]] = phi[i] * p[j];
        break;
      }
      phi[i * p[j]] = phi[i] * (p[j] - 1);
    }
  }
}
struct node {
  ll mn[B], tag;
} t[N * 4];
void up(int x) {
  for (int i = 0; i < B; ++i)
    t[x].mn[i] = min(t[x << 1].mn[i], t[x << 1 | 1].mn[i]) + t[x].tag;
}
void tag(int x, int val) {
  for (int i = 0; i < B; ++i) t[x].mn[i] += val;
  t[x].tag += val;
}
void modify(int x, int l, int r, int ql, int qr, int v) {
  if (ql <= l && r <= qr) {
    tag(x, v);
    return;
  }
  int mid = (l + r) >> 1;
  if (ql <= mid) modify(x << 1, l, mid, ql, qr, v);
  if (qr > mid) modify(x << 1 | 1, mid + 1, r, ql, qr, v);
  up(x);
}
void assign(int x, int l, int r, int p, const ll *v, int tag = 0) {
  if (l == r) {
    for (int i = 0; i < B; ++i) t[x].mn[i] = v[i] - tag;
    return;
  }
  int mid = (l + r) >> 1;
  tag += t[x].tag;
  p <= mid ? assign(x << 1, l, mid, p, v, tag)
           : assign(x << 1 | 1, mid + 1, r, p, v, tag);
  up(x);
}
void build(int x, int l, int r) {
  memset(t[x].mn, 0x3f, sizeof(t[x].mn));
  if (l == 0) t[x].mn[0] = 0;
  t[x].tag = 0;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(x << 1, l, mid);
  build(x << 1 | 1, mid + 1, r);
}
ll dp[N][B];
vector<int> di[N];
void prework(int n) {
  sieve(n);
  for (int i = 1; i <= n; ++i)
    for (int j = i; j <= n; j += i) di[j].push_back(i);
  build(1, 0, n);
  for (int i = 1; i <= n; ++i) {
    for (int d : di[i]) modify(1, 0, n, 0, d - 1, phi[i / d]);
    dp[i][0] = INF;
    for (int j = 0; j < B - 1; ++j) dp[i][j + 1] = t[1].mn[j];
    assign(1, 0, n, i, dp[i]);
  }
}
int main() {
  int qc;
  read(qc);
  prework(100000);
  while (qc--) {
    int n, k;
    read(n, k);
    if (k >= B)
      printf("%d\n", n);
    else
      printf("%lld\n", dp[n][k]);
  }
  return 0;
}
