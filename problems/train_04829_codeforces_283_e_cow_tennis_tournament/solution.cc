#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
int lazy[maxn * 4], ji[maxn * 4], len[maxn * 4];
void build(int i, int L, int R) {
  lazy[i] = ji[i] = 0;
  len[i] = R - L + 1;
  if (L == R) return;
  int mid = (L + R) >> 1;
  build(i << 1, L, mid);
  build((i << 1) | 1, mid + 1, R);
}
void getdown(int i) {
  lazy[i] ^= 1;
  ji[i] = len[i] - ji[i];
}
void push_down(int i) {
  getdown(i << 1);
  getdown((i << 1) | 1);
  lazy[i] = 0;
}
void modify(int i, int L, int R, int l, int r) {
  if (L == l && R == r) {
    getdown(i);
    return;
  }
  if (lazy[i]) push_down(i);
  int mid = (L + R) >> 1;
  if (mid >= r)
    modify(i << 1, L, mid, l, r);
  else if (mid < l)
    modify((i << 1) | 1, mid + 1, R, l, r);
  else {
    modify(i << 1, L, mid, l, mid);
    modify((i << 1) | 1, mid + 1, R, mid + 1, r);
  }
  ji[i] = ji[i << 1] + ji[(i << 1) | 1];
}
int ask(int i, int L, int R, int l, int r, int flag) {
  if (l > r) return 0;
  if (L == l && R == r) {
    if (flag == 0) return len[i] - ji[i];
    return ji[i];
  }
  if (lazy[i]) push_down(i);
  int mid = (L + R) >> 1;
  if (mid >= r)
    return ask(i << 1, L, mid, l, r, flag);
  else if (mid < l)
    return ask((i << 1) | 1, mid + 1, R, l, r, flag);
  return ask(i << 1, L, mid, l, mid, flag) +
         ask((i << 1) | 1, mid + 1, R, mid + 1, r, flag);
}
int s[maxn], n, k;
struct node {
  int l, r;
} a[maxn];
struct cmp {
  bool operator()(node &x, node &y) { return x.r > y.r; }
};
priority_queue<node, vector<node>, cmp> q;
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> s[i];
  sort(s + 1, s + n + 1);
  for (int i = 1; i <= k; i++) {
    cin >> a[i].l >> a[i].r;
    a[i].l = lower_bound(s + 1, s + n + 1, a[i].l) - s;
    a[i].r = upper_bound(s + 1, s + n + 1, a[i].r) - s - 1;
  }
  sort(a + 1, a + k + 1, [](node &x, node &y) { return x.l < y.l; });
  build(1, 1, n);
  int pos = 1;
  ll ans = 1LL * n * (n - 1) * (n - 2) / 6;
  for (int i = 1; i <= n; i++) {
    while (pos <= k && a[pos].l <= i) {
      if (a[pos].l <= a[pos].r) {
        modify(1, 1, n, a[pos].l, a[pos].r);
        q.push(a[pos]);
      }
      pos++;
    }
    int num = ask(1, 1, n, 1, i - 1, 0) + ask(1, 1, n, i + 1, n, 1);
    ans -= 1LL * num * (num - 1) / 2;
    while (!q.empty() && q.top().r <= i) {
      modify(1, 1, n, q.top().l, q.top().r);
      q.pop();
    }
  }
  cout << ans << "\n";
  return 0;
}
