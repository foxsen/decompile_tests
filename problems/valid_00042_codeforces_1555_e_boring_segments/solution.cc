#include <bits/stdc++.h>
using namespace std;
int n, m;
struct Seg {
  int l;
  int r;
  int w;
};
vector<int> segTree;
vector<int> lazyTree;
void updateSegT(int node, int st, int end, int l, int r, int val) {
  if (l > r) return;
  if (lazyTree[node]) {
    lazyTree[2 * node] += lazyTree[node];
    lazyTree[2 * node + 1] += lazyTree[node];
    segTree[node] += lazyTree[node];
    lazyTree[node] = 0;
  }
  if (l > end || r < st) return;
  if (st >= l && end <= r) {
    segTree[node] += val;
    lazyTree[2 * node] += val;
    lazyTree[2 * node + 1] += val;
  } else {
    int mid = (st + end) / 2;
    updateSegT(2 * node, st, mid, l, r, val);
    updateSegT(2 * node + 1, mid + 1, end, l, r, val);
    segTree[node] = min(segTree[2 * node], segTree[2 * node + 1]);
  }
}
vector<Seg> segs;
int main() {
  cin >> n >> m;
  m--;
  int nm = 1 << (int)ceil(log2(m));
  segTree.resize(nm * 2);
  lazyTree.resize(nm * 2 * 2);
  int l, r, w;
  for (int(i) = (0); (i) < (n); ++(i)) {
    cin >> l >> r >> w;
    segs.push_back({l, r - 1, w});
  }
  sort(segs.begin(), segs.end(),
       [](const Seg& a, const Seg& b) { return (a.w < b.w); });
  updateSegT(1, 1, nm, m + 1, nm, 3000001);
  int ans = INT_MAX;
  for (int p1 = 0, p2 = 0; p1 < n; p1++) {
    updateSegT(1, 1, nm, segs[p1].l, segs[p1].r, 1);
    if (!segTree[1]) continue;
    while (segTree[1]) {
      updateSegT(1, 1, nm, segs[p2].l, segs[p2].r, -1);
      p2++;
    }
    ans = min(ans, segs[p1].w - segs[p2 - 1].w);
  }
  cout << ans;
  return 0;
}
