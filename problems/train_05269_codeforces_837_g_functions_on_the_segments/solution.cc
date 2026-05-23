#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long mod = 1e9;
struct seg {
  int l, r, mid;
  long long sum = 0;
  seg *ch[2] = {NULL, NULL};
  void add(seg *prev, int pos, int val) {
    if (l == r) {
      sum = prev->sum + val;
      return;
    }
    if (pos <= mid) {
      ch[1] = prev->ch[1];
      ch[0] = new seg(l, mid);
      ch[0]->add(prev->ch[0], pos, val);
    } else {
      ch[0] = prev->ch[0];
      ch[1] = new seg(mid + 1, r);
      ch[1]->add(prev->ch[1], pos, val);
    }
    sum = ch[0]->sum + ch[1]->sum;
  }
  long long query(int _l, int _r) {
    if (_l <= l and _r >= r) return sum;
    if (_l > r or _r < l) return 0;
    return ch[0]->query(_l, _r) + ch[1]->query(_l, _r);
  }
  void init() {
    if (l == r) return;
    ch[0] = new seg(l, mid), ch[0]->init();
    ch[1] = new seg(mid + 1, r), ch[1]->init();
  }
  seg(int _l, int _r) { l = _l, r = _r, mid = l + r >> 1; }
};
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m;
  cin >> n;
  vector<seg *> rt(3 * n + 1), rt2(2 * n + 1);
  for (int i = 0; i <= n * 3; i++) rt[i] = new seg(0, N);
  for (int i = 0; i <= n * 2; i++) rt2[i] = new seg(0, N);
  rt[0]->init(), rt2[0]->init();
  for (int i = 0; i < n; i++) {
    int x1, x2, y1, a, b, y2;
    cin >> x1 >> x2 >> y1 >> a >> b >> y2;
    rt[i * 3 + 1]->add(rt[i * 3], 0, y1);
    rt[i * 3 + 2]->add(rt[i * 3 + 1], x1 + 1, b - y1);
    rt[i * 3 + 3]->add(rt[i * 3 + 2], x2 + 1, y2 - b);
    rt2[i * 2 + 1]->add(rt2[i * 2], x1 + 1, a);
    rt2[i * 2 + 2]->add(rt2[i * 2 + 1], x2 + 1, -a);
  }
  long long last = 0;
  cin >> m;
  while (m--) {
    long long l, r, x;
    cin >> l >> r >> x;
    long long tmp = (x + last) % mod;
    x = min((x + last) % mod, 200001ll);
    last = rt[r * 3]->query(0, x) - rt[(l - 1) * 3]->query(0, x) +
           tmp * (rt2[r * 2]->query(0, x) - rt2[(l - 1) * 2]->query(0, x));
    cout << last << '\n';
  }
}
