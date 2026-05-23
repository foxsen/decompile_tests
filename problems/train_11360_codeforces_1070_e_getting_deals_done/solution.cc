#include <bits/stdc++.h>
using namespace std;
struct node {
  long long sum;
  int cnt;
  node *ptl, *ptr;
  node() {
    sum = cnt = 0;
    ptl = ptr = NULL;
  }
  void build(int l, int r) {
    sum = cnt = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (ptl == NULL) ptl = new node();
    ptl->build(l, mid);
    if (ptr == NULL) ptr = new node();
    ptr->build(mid + 1, r);
  }
  void update(int l, int r, int tar, long long add) {
    sum += add;
    cnt++;
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (tar <= mid)
      ptl->update(l, mid, tar, add);
    else
      ptr->update(mid + 1, r, tar, add);
  }
  long long query(int l, int r, int need) {
    if (need == 0) return 0;
    if (l == r) return sum;
    int mid = (l + r) >> 1;
    if (ptl->cnt >= need) {
      return ptl->query(l, mid, need);
    } else {
      return ptl->sum + ptr->query(mid + 1, r, need - ptl->cnt);
    }
  }
} root;
int _T, n, m, arr[200055];
long long t;
vector<int> pos[200055], NUM;
inline long long solve(int tar) {
  if (tar == 0) return 0;
  long long blocks = (tar - 1) / m;
  return root.query(0, n - 1, blocks * m) + root.query(0, n - 1, tar);
}
int main() {
  scanf("%d", &_T);
  while (_T--) {
    int ans = 0, ans2 = 1;
    NUM.clear();
    scanf("%d%d%lld", &n, &m, &t);
    for (int i = 0; i < n; i++) {
      scanf("%d", arr + i);
      pos[arr[i]].push_back(i);
      NUM.push_back(arr[i]);
    }
    sort(NUM.begin(), NUM.end());
    NUM.resize(unique(NUM.begin(), NUM.end()) - NUM.begin());
    root.build(0, n - 1);
    int cnt = 0;
    for (int d : NUM) {
      for (int at : pos[d]) {
        root.update(0, n - 1, at, d);
        cnt++;
      }
      int lo = 0, hi = cnt + 1;
      while (lo < hi - 1) {
        int mid = (lo + hi) >> 1;
        if (solve(mid) <= t)
          lo = mid;
        else
          hi = mid;
      }
      if (lo > ans) {
        ans = lo;
        ans2 = d;
      }
    }
    printf("%d %d\n", ans, ans2);
    for (int i = 0; i < n; i++) pos[arr[i]].clear();
  }
  return 0;
}
