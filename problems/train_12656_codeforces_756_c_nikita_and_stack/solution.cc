#include <bits/stdc++.h>
using namespace std;
int mas[100100];
const int MAXN = 1 << 17;
const int MAXN2 = MAXN * 2;
int tree[MAXN2];
int treeres[MAXN2];
void adfsadsad(int idx, int L, int R, int pos, int val) {
  if (L == R) {
    tree[idx] = val;
    treeres[idx] = val;
    return;
  }
  int mid = (L + R) / 2;
  if (pos <= mid)
    adfsadsad(idx * 2, L, mid, pos, val);
  else
    adfsadsad(idx * 2 + 1, mid + 1, R, pos, val);
  tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
  treeres[idx] =
      max(tree[idx * 2 + 1] + treeres[idx * 2], treeres[idx * 2 + 1]);
}
void setvalue(int pos) { adfsadsad(1, 0, MAXN - 1, pos, 1); }
void ervalue(int pos) { adfsadsad(1, 0, MAXN - 1, pos, -1); }
int get(int idx, int L, int R, int cursum) {
  if (L == R) {
    if (cursum + tree[idx] > 0)
      return L;
    else
      return -1;
  }
  int mid = (L + R) / 2;
  if (cursum + treeres[idx * 2 + 1] > 0)
    return get(idx * 2 + 1, mid + 1, R, cursum);
  else
    return get(idx * 2, L, mid, cursum + tree[idx * 2 + 1]);
}
int solve() { return get(1, 0, MAXN - 1, 0); }
int main() {
  int m;
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    int p, t;
    scanf("%d %d", &p, &t);
    if (t == 1) {
      int x;
      scanf("%d", &x);
      mas[p] = x;
      setvalue(p);
    } else {
      ervalue(p);
    }
    int s = solve();
    if (s != -1) s = mas[s];
    printf("%d\n", s);
  }
  return 0;
}
