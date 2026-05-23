#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
struct node {
  int vl, mnvl;
  node *l, *r;
  node() {
    mnvl = MAXN;
    vl = -1;
    l = r = NULL;
  }
};
vector<node*> dv(MAXN);
vector<bool> inarr(MAXN, false);
vector<vector<int>> diverse(MAXN);
deque<int> dbl(int a) {
  deque<int> d;
  while (a != 0) d.push_front(a % 2), a /= 2;
  while (d.size() != 18) d.push_front(0);
  return d;
}
void ins(node* d, deque<int> a, int n) {
  while (!a.empty()) {
    d->mnvl = min(d->mnvl, n);
    int b = a.front();
    a.pop_front();
    if (b == 0) {
      if (d->l == NULL) d->l = new node();
      d = d->l;
    } else {
      if (d->r == NULL) d->r = new node();
      d = d->r;
    }
  }
  d->vl = n;
  d->mnvl = min(d->mnvl, n);
}
int fnd(node* d, deque<int> xd, int s, int x) {
  while (!xd.empty()) {
    int xx = xd.front();
    xd.pop_front();
    if (xx == 0)
      if (d->r != NULL && d->r->mnvl + x <= s)
        d = d->r;
      else if (d->l != NULL && d->l->mnvl + x <= s)
        d = d->l;
      else
        return -1;
    else if (d->l != NULL && d->l->mnvl + x <= s)
      d = d->l;
    else if (d->r != NULL && d->r->mnvl + x <= s)
      d = d->r;
    else
      return -1;
  }
  return d->vl;
}
int main() {
  for (int i = 1; i < MAXN; i++)
    for (int j = i; j < MAXN; j += i) diverse[j].push_back(i);
  for (int i = 1; i < dv.size(); i++) dv[i] = new node();
  int n, q, a, x, k, s;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> q;
    if (q == 1) {
      cin >> a;
      if (!inarr[a]) {
        inarr[a] = true;
        deque<int> d = dbl(a);
        for (int i = 0; i < diverse[a].size(); i++)
          ins(dv[diverse[a][i]], d, a);
      }
    } else {
      cin >> x >> k >> s;
      if (x % k != 0 || s - x <= 0)
        cout << -1 << endl;
      else
        cout << fnd(dv[k], dbl(x), s, x) << endl;
    }
  }
  return 0;
}
