#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
struct p {
  int x, id;
  bool operator<(const p &a) const { return x < a.x; }
} a[MAX];
int n, ans, K;
int fa[MAX], siz[MAX], tot[MAX], b[MAX];
set<int> S;
int find(int x) {
  if (fa[x] != x) fa[x] = find(fa[x]);
  return fa[x];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i].x), b[i] = a[i].x, a[i].id = i, fa[i] = i, siz[i] = 1;
  sort(a + 1, a + 1 + n);
  b[0] = b[n + 1] = 2e9;
  for (int i = 1; i <= n; ++i) {
    int id = a[i].id, k = a[i].x + 1;
    if (k == 61) {
      cout << "";
    }
    S.insert(1), ++tot[1];
    if (b[id - 1] < k) {
      int r1 = find(id - 1);
      --tot[1], --tot[siz[r1]];
      if (!tot[1]) S.erase(1);
      if (!tot[siz[r1]]) S.erase(siz[r1]);
      fa[id] = r1, ++tot[++siz[r1]];
      if (tot[siz[r1]] == 1) S.insert(siz[r1]);
    }
    if (b[id + 1] < k) {
      int r1 = find(id + 1), r2 = find(id);
      --tot[siz[r1]], --tot[siz[r2]];
      if (!tot[siz[r1]]) S.erase(siz[r1]);
      if (!tot[siz[r2]]) S.erase(siz[r2]);
      fa[r1] = r2, ++tot[siz[r2] += siz[r1]];
      if (tot[siz[r2]] == 1) S.insert(siz[r2]);
    }
    if (S.size() == 1 && tot[*S.begin()] > ans) ans = tot[*S.begin()], K = k;
  }
  return printf("%d", K), 0;
}
