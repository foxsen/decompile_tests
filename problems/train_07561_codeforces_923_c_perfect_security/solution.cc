#include <bits/stdc++.h>
using namespace std;
struct node {
  long l, r, cnt;
};
node mn(long x, long y, long z) {
  node tmp;
  tmp.l = x;
  tmp.r = y;
  tmp.cnt = z;
  return tmp;
}
vector<node> tree;
void put(long x) {
  bool b[30] = {};
  long i = 0;
  while (x) {
    b[i] = x % 2;
    x >>= 1;
    i++;
  }
  long now = 1;
  tree[now].cnt++;
  i = 29;
  while (i >= 0) {
    if (b[i]) {
      if (tree[now].l == 0) {
        tree.push_back(mn(0, 0, 0));
        tree[now].l = (long)(tree).size() - 1;
        now = (long)(tree).size() - 1;
      } else
        now = tree[now].l;
    } else {
      if (tree[now].r == 0) {
        tree.push_back(mn(0, 0, 0));
        tree[now].r = (long)(tree).size() - 1;
        now = (long)(tree).size() - 1;
      } else
        now = tree[now].r;
    }
    tree[now].cnt++;
    i--;
  }
}
long get(long x) {
  long ans = 0;
  bool b[30] = {};
  long i = 0;
  while (x) {
    b[i] = x % 2;
    x /= 2;
    i++;
  }
  long now = 1;
  tree[now].cnt--;
  i = 29;
  while (i >= 0) {
    long ho = 0;
    if (b[i]) {
      if (tree[now].l != 0 && tree[tree[now].l].cnt != 0) {
        now = tree[now].l;
        ho = 1;
      } else {
        now = tree[now].r;
      }
    } else {
      if (tree[now].r != 0 && tree[tree[now].r].cnt != 0) {
        now = tree[now].r;
      } else {
        now = tree[now].l;
        ho = 1;
      }
    }
    tree[now].cnt--;
    ans *= 2;
    ans += ho;
    i--;
  }
  return ans;
}
int main() {
  cout << fixed << setprecision(15);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  tree.push_back(mn(0, 0, 0));
  tree.push_back(mn(0, 0, 0));
  long n;
  cin >> n;
  vector<long> a, p, ans;
  for (long long f = (long long)(0); f <= (long long)(n - 1); ++f) {
    long x;
    cin >> x;
    a.push_back(x);
  }
  for (long long f = (long long)(0); f <= (long long)(n - 1); ++f) {
    long x;
    cin >> x;
    p.push_back(x);
  }
  for (long long f = (long long)(0); f <= (long long)(n - 1); ++f) {
    put(p[f]);
  }
  for (long long f = (long long)(0); f <= (long long)(n - 1); ++f) {
    long now = get(a[f]);
    ans.push_back(a[f] ^ now);
  }
  for (long long f = (long long)(0); f <= (long long)(n - 1); ++f) {
    cout << ans[f] << ' ';
  }
  return 0;
}
