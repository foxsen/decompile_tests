#include <bits/stdc++.h>
using namespace std;
const int nmax = 100010;
const int inf = (int)1e8;
int n, a[nmax], last[nmax], distinct;
int ans[nmax];
struct Node {
  Node *left, *right;
  int sum;
  Node() {
    left = right = NULL;
    sum = 0;
  }
  int getSum(Node *v) { return (v ? v->sum : 0); }
  void update() { this->sum = getSum(this->left) + getSum(this->right); }
  Node(Node *l, Node *r) {
    left = l;
    right = r;
    sum = getSum(left) + getSum(right);
  }
  Node(int el) {
    left = right = NULL;
    sum = el;
  }
};
Node *t[nmax];
Node *build(int tl, int tr) {
  if (tl == tr)
    return new Node(0);
  else {
    int m = (tl + tr) >> 1;
    return new Node(build(tl, m), build(m + 1, tr));
  }
}
Node *update(Node *t, int tl, int tr, int pos, int val) {
  if (tl == tr) return new Node(val);
  int m = (tl + tr) >> 1;
  if (pos <= m)
    return new Node(update(t->left, tl, m, pos, val), t->right);
  else
    return new Node(t->left, update(t->right, m + 1, tr, pos, val));
}
int get(Node *t, int tl, int tr, int k) {
  if (tl == tr) return (k == 0 && t->sum == 1 ? tl - 1 : tl);
  int m = (tl + tr) >> 1;
  if (t->left->sum <= k) return get(t->right, m + 1, tr, k - t->left->sum);
  return get(t->left, tl, m, k);
}
void println(Node *t, int tl, int tr) {
  if (tl == tr)
    cout << t->sum << " ";
  else {
    int m = (tl + tr) >> 1;
    println(t->left, tl, m);
    println(t->right, m + 1, tr);
  }
}
int calc(int k) {
  int i = 1;
  int groups = 0;
  while (i <= n) {
    int j = get(t[i], 1, n + 1, k);
    i = j + 1;
    groups++;
  }
  return groups;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  t[n] = build(1, n + 1);
  t[n] = update(t[n], 1, n + 1, n, 1);
  last[a[n]] = n;
  for (int i = n - 1, x; i >= 1; i--) {
    x = a[i];
    t[i] = t[i + 1];
    if (last[x] != 0) t[i] = update(t[i], 1, n + 1, last[x], 0);
    t[i] = update(t[i], 1, n + 1, i, 1);
    last[x] = i;
  }
  for (int i = 1; i <= n; i++) cout << calc(i) << " ";
  cout << endl;
}
