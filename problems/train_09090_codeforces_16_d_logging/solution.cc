#include <bits/stdc++.h>
using namespace std;
const int Mod = 1e9 + 9;
struct node {
  int l, r;
  bool operator<(const node &a) const {
    if (l == a.l) return r < a.r;
    return l < a.l;
  }
  bool operator==(const node &a) const { return a.l == l && a.r == r; }
};
int n;
node tim[500005];
char c;
void solve() {
  memset(tim, 0, sizeof(tim));
  scanf("%d", &n);
  getchar();
  for (int i = 0; i < n; i++) {
    int cnt = 1;
    while (c = getchar()) {
      if (c == '\n') break;
      if (c >= '0' && c <= '9' && cnt >= 0) {
        if (cnt == 1)
          tim[i].l *= 10, tim[i].l += c - '0';
        else
          tim[i].r *= 10, tim[i].r += c - '0';
      }
      if (c == ':' && cnt >= 0) cnt = 0;
      if (c == 'm') cnt = -1;
      if (c == 'p' && cnt != -1) cnt = -1, tim[i].l += 12;
    }
  }
  int ans = 1, cnt = 0;
  node la = tim[0];
  if (la.l == 12) la.l = 0;
  if (la.l == 24) la.l = 12;
  for (int i = 1; i < n; i++) {
    if (tim[i].l == 12)
      tim[i].l = 0;
    else if (tim[i].l == 24)
      tim[i].l = 12;
    if (tim[i] < la)
      cnt = 0, la = tim[i], ans++;
    else if (tim[i] == la)
      cnt++;
    else
      la = tim[i], cnt = 0;
    if (cnt >= 10) ans++, cnt -= 10;
  }
  if (cnt > 10) ans++;
  cout << ans << endl;
}
int main() {
  int t = 10000;
  solve();
  int mk;
  if (scanf("%d", &mk) == EOF) return 0;
  return 0;
}
