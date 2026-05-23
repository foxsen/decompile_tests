#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e4 + 50;
int n, m, mod, a[maxn], len, F[maxn << 1];
int sz, bnum, cnt[maxn], belong[maxn], ans[maxn];
vector<int> v;
struct Tree {
  int le, ri;
  int shift, S1, S2;
} tree[maxn << 2];
void move(int& S1, int& S2, int k) {
  int newS1 = (S1 * F[len + k - 1] + S2 * F[len + k]) % mod;
  int newS2 = (S1 * F[len + k] + S2 * F[len + k + 1]) % mod;
  S1 = newS1;
  S2 = newS2;
}
void pushup(int id) {
  tree[id].S1 = (tree[id << 1].S1 + tree[id << 1 | 1].S1) % mod;
  tree[id].S2 = (tree[id << 1].S2 + tree[id << 1 | 1].S2) % mod;
}
void pushdown(int id) {
  if (tree[id].shift) {
    tree[id << 1].shift += tree[id].shift;
    move(tree[id << 1].S1, tree[id << 1].S2, tree[id].shift);
    tree[id << 1 | 1].shift += tree[id].shift;
    move(tree[id << 1 | 1].S1, tree[id << 1 | 1].S2, tree[id].shift);
    tree[id].shift = 0;
  }
}
void build(int id, int le, int ri) {
  tree[id].le = le;
  tree[id].ri = ri;
  tree[id].shift = tree[id].S1 = tree[id].S2 = 0;
  if (le == ri) return;
  int mid = (le + ri) >> 1;
  build(id << 1, le, mid);
  build(id << 1 | 1, mid + 1, ri);
}
void Insert(int id, int pos, int val) {
  if (tree[id].le == tree[id].ri) {
    tree[id].S1 = 1LL * val * F[len + tree[id].shift] % mod;
    tree[id].S2 = 1LL * val * F[len + tree[id].shift + 1] % mod;
    return;
  }
  pushdown(id);
  int mid = (tree[id].le + tree[id].ri) >> 1;
  if (pos <= mid) {
    tree[id << 1 | 1].shift += 1;
    move(tree[id << 1 | 1].S1, tree[id << 1 | 1].S2, 1);
    Insert(id << 1, pos, val);
  } else
    Insert(id << 1 | 1, pos, val);
  pushup(id);
}
void Remove(int id, int pos) {
  if (tree[id].le == tree[id].ri) {
    tree[id].S1 = tree[id].S2 = 0;
    return;
  }
  pushdown(id);
  int mid = (tree[id].le + tree[id].ri) >> 1;
  if (pos <= mid) {
    tree[id << 1 | 1].shift -= 1;
    move(tree[id << 1 | 1].S1, tree[id << 1 | 1].S2, -1);
    Remove(id << 1, pos);
  } else
    Remove(id << 1 | 1, pos);
  pushup(id);
}
struct Node {
  int id, le, ri;
} q[maxn];
bool cmp(Node x, Node y) {
  return (belong[x.le] ^ belong[y.le])
             ? belong[x.le] < belong[y.le]
             : ((belong[x.le] & 1) ? x.ri < y.ri : x.ri > y.ri);
}
void Add(int pos) {
  pos = lower_bound(v.begin(), v.end(), a[pos]) - v.begin() + 1;
  if (!cnt[pos]++) Insert(1, pos, v[pos - 1]);
}
void Del(int pos) {
  pos = lower_bound(v.begin(), v.end(), a[pos]) - v.begin() + 1;
  if (!--cnt[pos]) Remove(1, pos);
}
int main() {
  scanf("%d%d", &n, &mod);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    v.push_back(a[i]);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  len = v.size();
  F[len] = 0;
  F[len + 1] = 1;
  for (int i = 2; i + len < (maxn << 1); ++i)
    F[i + len] = (F[i + len - 1] + F[i + len - 2]) % mod;
  for (int i = -1; i + len >= 0; --i)
    F[i + len] = (F[i + len + 2] - F[i + len + 1] + mod) % mod;
  build(1, 1, len);
  sz = sqrt(n);
  bnum = ceil(double(n / sz));
  for (int i = 1; i <= bnum; ++i) {
    for (int j = (i - 1) * sz + 1; j <= i * sz && j <= n; ++j) {
      belong[j] = i;
    }
  }
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &q[i].le, &q[i].ri);
    q[i].id = i;
  }
  sort(q, q + m, cmp);
  int L = 1, R = 0;
  for (int i = 0; i < m; ++i) {
    while (L < q[i].le) Del(L++);
    while (L > q[i].le) Add(--L);
    while (R < q[i].ri) Add(++R);
    while (R > q[i].ri) Del(R--);
    ans[q[i].id] = tree[1].S2;
  }
  for (int i = 0; i < m; ++i) printf("%d\n", ans[i]);
  return 0;
}
